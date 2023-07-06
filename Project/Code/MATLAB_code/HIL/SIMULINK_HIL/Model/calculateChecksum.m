function crc_var = calculateChecksum(input_value)
    ply =uint16(hex2dec('8408'));
    crc_var =uint16(0);
    l = numel(input_value);
    
    for j = 1:l
        value = uint16(input_value(j));
        for i = 1:8
            m = (bitand(value,1) && bitand(crc_var,1));
            n = (bitand(value,1) || bitand(crc_var,1));
        
              if (m ==  1 || (m == 0 && n ~=1))
        
                  crc_var = bitshift(crc_var, -1);
                  value = bitshift(value, -1);
        
             elseif (n == 1)            
                      crc_var_temp = bitshift(crc_var, -1);
                      crc_var = bitxor(crc_var_temp,ply);
                      value = bitshift(value, -1);
              end
        end
    end
end