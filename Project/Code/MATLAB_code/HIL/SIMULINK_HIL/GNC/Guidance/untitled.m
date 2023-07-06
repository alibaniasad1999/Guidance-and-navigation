data = [1 0 1 1 0 1 0 ];
checksum = calculateChecksum(data);
disp(['Checksum: ' num2str(checksum)]);






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
