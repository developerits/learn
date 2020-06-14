-- Copyright (C) 2019  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and any partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details, at
-- https://fpgasoftware.intel.com/eula.

-- Generated by Quartus Prime Version 19.1.0 Build 670 09/22/2019 SJ Lite Edition
-- Created on Wed Jun 03 08:37:50 2020

LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY SM_Mealy IS
    PORT (
        reset : IN STD_LOGIC := '0';
        clock : IN STD_LOGIC;
        sno : IN STD_LOGIC := '0';
        x : IN STD_LOGIC_VECTOR(2 DOWNTO 0) := "000";
        y : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);
        sko : OUT STD_LOGIC
    );
END SM_Mealy;

ARCHITECTURE BEHAVIOR OF SM_Mealy IS
    TYPE type_fstate IS (s0,s1,s2,s3);
    SIGNAL fstate : type_fstate;
    SIGNAL reg_fstate : type_fstate;
BEGIN
    PROCESS (clock,reset,reg_fstate)
    BEGIN
        IF (reset='1') THEN
            fstate <= s0;
        ELSIF (clock='1' AND clock'event) THEN
            fstate <= reg_fstate;
        END IF;
    END PROCESS;

    PROCESS (fstate,sno,x)
    BEGIN
        y <= "0000000000";
        sko <= '0';
        CASE fstate IS
            WHEN s0 =>
                IF ((sno = '1')) THEN
                    reg_fstate <= s1;
                ELSIF (NOT((sno = '1'))) THEN
                    reg_fstate <= s0;
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    reg_fstate <= s0;
                END IF;

                IF (NOT((sno = '1'))) THEN
                    y <= "0000000000";
                ELSIF ((sno = '1')) THEN
                    y <= "0000001111";
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    y <= "0000000000";
                END IF;
            WHEN s1 =>
                IF ((x(0) = '1')) THEN
                    reg_fstate <= s2;
                ELSIF (NOT((x(0) = '1'))) THEN
                    reg_fstate <= s3;
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    reg_fstate <= s1;
                END IF;

                IF ((x(0) = '1')) THEN
                    y <= "0000110000";
                ELSIF ((NOT((x(0) = '1')) AND (x(1) = '1'))) THEN
                    y <= "0001000000";
                ELSIF ((NOT((x(0) = '1')) AND NOT((x(1) = '1')))) THEN
                    y <= "0010000000";
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    y <= "0000000000";
                END IF;
            WHEN s2 =>
                reg_fstate <= s3;

                IF ((x(1) = '1')) THEN
                    y <= "0001000000";
                ELSIF (NOT((x(1) = '1'))) THEN
                    y <= "0010000000";
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    y <= "0000000000";
                END IF;
            WHEN s3 =>
                IF ((x(2) = '1')) THEN
                    reg_fstate <= s0;
                ELSIF (NOT((x(2) = '1'))) THEN
                    reg_fstate <= s2;
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    reg_fstate <= s3;
                END IF;

                IF ((x(2) = '1')) THEN
                    sko <= '1';
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    sko <= '0';
                END IF;

                IF (NOT((x(2) = '1'))) THEN
                    y <= "1100000000";
                -- Inserting 'else' block to prevent latch inference
                ELSE
                    y <= "0000000000";
                END IF;
            WHEN OTHERS => 
                y <= "XXXXXXXXXX";
                sko <= 'X';
                report "Reach undefined state";
        END CASE;
    END PROCESS;
END BEHAVIOR;