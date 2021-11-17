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

cd %~p1
if not exist %1 goto END
if "%2" == "clean" goto CLEAN
if "%2" == "cleanlog" goto CLEANLOG

echo Running %~p1 >&3

::���O�t�@�C���ɐi�s�󋵂���������
if not "%2" == "" echo Running %1

::�^�C���X�^���v
echo ---auto test for ��ITRON4.0 (%DRIVE_K%)---- > test.log
echo -----Running %~p1  %DATE% %TIME%----- >> test.log

if exist test.bat call test.bat > temp.log
if exist testx.bat call testx.bat > temp.log
GOTO ERROR_%ERRORLEVEL%

:ERROR_0
type temp.log | findstr "**** Step" >> test.log
type temp.log | find "****"
if not errorlevel 1 goto ERROR
type temp.log | find "---Reached Last" 
if errorlevel 1 goto ERROR
call %BAT_DIR%exec_auto.bat %1 clean
GOTO END

::�G���[�����������ꍇ�A�G���[���b�Z�[�W���o��
:ERROR_2
type temp.log | findstr "**** Step" >> test.log
:ERROR
echo Error(s) found
goto END

:ERROR_1
if "%No_Errors_Find%"=="" GOTO END
echo Error(s) "�G���[�̖����o"
type temp.log | findstr "**** Step" >> test.log
type test.log | find "***No errors"
goto END

:::::::::::���O�t�@�C�����폜:::::::::::::
:CLEANLOG
del test.log 2>nul
del temp.log 2>nul
goto END

:CLEAN
if exist mvc.log rmdir  mvc.log /s /q
if exist test.bat call test.bat clean
if exist testx.bat call testx.bat clean

:END
if "%TEMP_LOG%"=="" del temp.log 2>nul
cd %BAT_DIR%

