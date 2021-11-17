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


if "%1" == "clean" goto CLEAN

build -all -progress -noreasons %DEFAULT_BLD% std_test.bld %TEST_CASE%.bld %TEST_CASE%%BLD_FILE%.bld 2>>test.log
if errorlevel 1 GOTO ERROR
IF %GRUN_TEST% == 0 GOTO END0

if exist test.i del test.i 2>nul
if not exist test goto ERROR
echo -----Executing grun------- >&3
grun -timeout=%TIMEOUT_SVR% %DEBUG_SVR% -- test
:END0
SET ERRORLEVEL=0
goto END

:ERROR
echo ***Build failed*** >> test.log
SET ERRORLEVEL=2
goto END

:CLEAN
build -clean %TEST_CASE%%BLD_FILE%.bld 2>> nul
del kernel_cfg.c 2>nul
del kernel_id.h  2>nul
if exist obj rmdir /s /q obj 2>nul
del *.map   2>nul
del *.inf   2>nul
SET ERRORLEVEL=0

:END