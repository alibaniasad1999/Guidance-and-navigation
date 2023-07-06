%% Parsing data from serial port %%
function y = fcn(u)
    persistent counter data begin y_final
    n = 50;
    y = zeroes(1, 2*n);
    if isempty(y_final)
        y_final = zeroes(1, 2*n)
    end
    if isempty(counter)
        counter = 0;
    end
    if isempty(begin)
        begin = false;
    end
    if isempty(data)
        data = zeroes(1, 2*n);
    end

    for i=1:length(u)
        if i ~= length(u) && u(i) == 85 && u(i+1) == 85
            begin = true;
            counter = 0;
        end
        if begin
            counter = counter + 1;
            data(counter) = u(i);
        end
        if counter == 2*n+1 % last one is checksum
            inchecksum = u(i);
            begin = false;
            counter = 0;
            checksum = calculateChecksum(data);
            if checksum == inchecksum % just check
                y_final = data;
            end
        end
    y = y_final;
end


function checksum = calculateChecksum(data)
    generatorPolynomial = hex2dec('8005');  % CRC-16 generator polynomial (binary: 1000000000000101)
    
    % Append zeros to data
    augmentedData = [data, zeros(1, 16)];
    
    % Perform polynomial division
    len = length(augmentedData);
    remainder = augmentedData(1);
    for i = 2:len
        if remainder(1) == 1
            remainder = bitxor(bitshift(remainder, 1), generatorPolynomial);
        else
            remainder = bitshift(remainder, 1);
        end
        remainder = bitxor(remainder, augmentedData(i));
    end
    
    checksum = remainder;
end
