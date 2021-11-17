::/* TOPPERS�J�[�l���e�X�g�X�C�[�g
:: * 
:: *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
:: * 
:: *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation
:: *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
:: *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
:: *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
:: *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
:: *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
:: *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
:: *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
:: *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
:: *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
:: *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
:: *      �̖��ۏ؋K����f�ڂ��邱�ƁD
:: *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
:: *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
:: *      �ƁD
:: *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
:: *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
:: *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
:: *        �񍐂��邱�ƁD
:: *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
:: *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
:: * 
:: *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
:: *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
:: *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
:: *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
:: */

@echo off
if "%BAT_DIR%" == "" goto ERROR
SET TEST_DIR=%BAT_DIR%test_case\
::-----------�R���t�B�M�����[�^�̃G���[�����o�̌��ʕ\���I��------::
::--- �G���[�����o�̌��ʂ�\������Ƃ��ɂ� No_Errors_Find=1 �ɕύX---::
::SET No_Errors_Find=1
SET No_Errors_Find=
::-----------���݂̃��[�L���O�f�B���N�g����ۑ�-----------::
for /F  "tokens=1*" %%V in ('cd') do set CUR_DIR=%%V
cd %BAT_DIR%
if "%FULL_TEST%"=="_jsp" (
dir /B /S /ON test_case\%1\test.bat | sort > dir.tmp
) ELSE (
dir /B /S /ON test_case\%1\test?.bat | sort > dir.tmp
)
if "%2" == "clean" goto %2
if "%2" == "cleanlog" goto %2
if "%2" == "dumplog" goto %2

if "%2"=="" set output_auto_test="&3" 
if not "%2" == "" set output_auto_test=%CUR_DIR%\%2

if not exist setup.bat goto ERROR
call setup.bat SET_ENV

::�o�b�`�t�@�C�����Ăяo�����f�B���N�g���Ƃ��̃T�u�f�B���N�g����
::�e�X�g�X�C�g�����s
echo ---auto test for ��ITRON4.0 (%DRIVE_K%)---- > %output_auto_test%
echo ---Time Stamp %DATE% %TIME%----- >> %output_auto_test%
echo.

for /F "tokens=* delims=" %%i in (dir.tmp) do call exec_auto.bat %%i %2 >> %output_auto_test%
echo ---Done %DATE% %TIME%---- >> %output_auto_test%
goto END

::::::::::���ԃt�@�C�����폜::::::::::
:cleanlog
set output_auto_test="nul" 
echo Cleaning log files

for /F "tokens=* delims=" %%i in (dir.tmp) do call exec_auto.bat %%i %2
goto END

:clean
set output_auto_test="nul" 
echo Cleaning intermediate files

for /F "tokens=* delims=" %%i in (dir.tmp) do call exec_auto.bat %%i %2
build -clean -noprogress default.bld 2>nul
goto END

:dumplog
set output_auto_test=%CUR_DIR%\%3.log
echo Dump log into %CUR_DIR%\%3.log
if exist %output_auto_test% del %output_auto_test% > nul
dir /B /S /ON test_case\%1\test.log | sort > dir.tmp
for /F "tokens=* delims=" %%i in (dir.tmp) do call dumplog.bat %%i >> %output_auto_test%
goto END

:ERROR
echo ***Error(s) occured while performing the test***

:END
cd %BAT_DIR%
if exist setup.bat call setup.bat DEL_ENV
del dir.tmp 2>nul
set TEST_DIR=
cd %CUR_DIR%
set CUR_DIR=
set output_auto_test=
