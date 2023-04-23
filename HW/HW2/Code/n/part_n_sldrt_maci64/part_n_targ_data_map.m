    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (part_n_P)
        ;%
            section.nData     = 69;
            section.data(69)  = dumData; %prealloc

                    ;% part_n_P.attitude_m0
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% part_n_P.attitude_t0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% part_n_P.d_state_m
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% part_n_P.d_state_t
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 7;

                    ;% part_n_P.k_epsilon_lead_angle
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 10;

                    ;% part_n_P.k_sigma_lead_angle
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% part_n_P.state_m0
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% part_n_P.state_t0
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 15;

                    ;% part_n_P.MinMaxRunningResettable_vinit
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 18;

                    ;% part_n_P.Constant_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 19;

                    ;% part_n_P.Constant3_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 20;

                    ;% part_n_P.Delay_InitialCondition
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 21;

                    ;% part_n_P.Constant4_Value
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 22;

                    ;% part_n_P.Switch_Threshold
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 23;

                    ;% part_n_P.Constant3_Value_i
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 24;

                    ;% part_n_P.Delay_InitialCondition_k
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 25;

                    ;% part_n_P.Constant4_Value_c
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 26;

                    ;% part_n_P.Switch_Threshold_i
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 27;

                    ;% part_n_P.Constant7_Value
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 28;

                    ;% part_n_P.Constant8_Value
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 29;

                    ;% part_n_P.Constant9_Value
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 32;

                    ;% part_n_P.Delay1_InitialCondition
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 33;

                    ;% part_n_P.TransferFcn_A
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 34;

                    ;% part_n_P.TransferFcn_C
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 35;

                    ;% part_n_P.TransferFcn_D
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 36;

                    ;% part_n_P.TransferFcn4_A
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 37;

                    ;% part_n_P.TransferFcn4_C
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 38;

                    ;% part_n_P.TransferFcn4_D
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 39;

                    ;% part_n_P.Delay_InitialCondition_i
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 40;

                    ;% part_n_P.TransferFcn2_A
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 41;

                    ;% part_n_P.TransferFcn2_C
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 42;

                    ;% part_n_P.TransferFcn2_D
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 43;

                    ;% part_n_P.TransferFcn_A_a
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 44;

                    ;% part_n_P.TransferFcn_C_i
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 45;

                    ;% part_n_P.TransferFcn_D_j
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 46;

                    ;% part_n_P.TransferFcn_A_j
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 47;

                    ;% part_n_P.TransferFcn_C_o
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 48;

                    ;% part_n_P.TransferFcn_D_c
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 49;

                    ;% part_n_P.TransferFcn_A_jp
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 50;

                    ;% part_n_P.TransferFcn_C_m
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 51;

                    ;% part_n_P.TransferFcn_D_f
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 52;

                    ;% part_n_P.TransferFcn1_A
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 53;

                    ;% part_n_P.TransferFcn1_C
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 54;

                    ;% part_n_P.TransferFcn1_D
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 55;

                    ;% part_n_P.TransferFcn4_A_p
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 56;

                    ;% part_n_P.TransferFcn4_C_a
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 57;

                    ;% part_n_P.TransferFcn4_D_g
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 58;

                    ;% part_n_P.TransferFcn2_A_a
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 59;

                    ;% part_n_P.TransferFcn2_C_b
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 60;

                    ;% part_n_P.TransferFcn2_D_p
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 61;

                    ;% part_n_P.TransferFcn3_A
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 62;

                    ;% part_n_P.TransferFcn3_C
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 63;

                    ;% part_n_P.TransferFcn3_D
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 64;

                    ;% part_n_P.Constant_Value_p
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 65;

                    ;% part_n_P.Switch_Threshold_g
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 66;

                    ;% part_n_P.Saturation_UpperSat
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 67;

                    ;% part_n_P.Saturation_LowerSat
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 68;

                    ;% part_n_P.Step_Time
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 69;

                    ;% part_n_P.Step_Y0
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 70;

                    ;% part_n_P.Step_YFinal
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 71;

                    ;% part_n_P.Step1_Time
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 72;

                    ;% part_n_P.Step1_Y0
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 73;

                    ;% part_n_P.Step1_YFinal
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 74;

                    ;% part_n_P.Gain_Gain
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 75;

                    ;% part_n_P.Constant1_Value
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 76;

                    ;% part_n_P.TransferFcn_A_l
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 77;

                    ;% part_n_P.TransferFcn_C_c
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 79;

                    ;% part_n_P.TransferFcn1_A_o
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 81;

                    ;% part_n_P.TransferFcn1_C_e
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 83;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (part_n_B)
        ;%
            section.nData     = 22;
            section.data(22)  = dumData; %prealloc

                    ;% part_n_B.Square
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% part_n_B.Memory
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% part_n_B.Reset
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% part_n_B.Delay
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% part_n_B.Delay_f
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% part_n_B.Delay1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% part_n_B.R_m
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% part_n_B.Delay_k
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 9;

                    ;% part_n_B.d_sigma
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 10;

                    ;% part_n_B.R_m_o
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 11;

                    ;% part_n_B.d_epsilon
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 12;

                    ;% part_n_B.Saturation
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 13;

                    ;% part_n_B.d_state
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 15;

                    ;% part_n_B.d_state_j
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 18;

                    ;% part_n_B.dd_state
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 21;

                    ;% part_n_B.dot_attitude
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 24;

                    ;% part_n_B.dd_state_o
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 26;

                    ;% part_n_B.dot_attitude_j
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 29;

                    ;% part_n_B.d_sigma_e
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 31;

                    ;% part_n_B.d_epsilon_n
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 32;

                    ;% part_n_B.epsilon_t
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 33;

                    ;% part_n_B.sigma_t
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 34;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% part_n_B.AND
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (part_n_DW)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% part_n_DW.Delay_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% part_n_DW.Delay_DSTATE_f
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% part_n_DW.Delay1_DSTATE
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% part_n_DW.Delay_DSTATE_j
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% part_n_DW.Memory_PreviousInput
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 4057179754;
    targMap.checksum1 = 2287370092;
    targMap.checksum2 = 1756152176;
    targMap.checksum3 = 1270584000;

