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
:::--- TEMP_LOG=1 �͊e�e�X�g���ڂ̎��s���쐬����� temp.log ��
:::--- �폜�����A�ۑ����Ă����ݒ�B
:::--- ���̐ݒ���폜����ƁAtemp.log ���폜�����
SET TEMP_LOG=1

IF "%O_PATH%"=="" SET O_PATH=%PATH%

IF "%1"=="help" GOTO ERROR0
IF "%1"=="" GOTO ERROR0

SET DRIVE_K=
SET FULL_TEST=_fi4
IF "%1"=="j" SET FULL_TEST=_jsp

IF "%1"=="j" SET DRIVE_K=C:\TOPPERS\jsp141
IF "%1"=="f" SET DRIVE_K=C:\TOPPERS\fi4
IF "%DRIVE_K%" == "" GOTO ERROR1

subst k: /D >nul
subst k: %DRIVE_K%
if errorlevel 1 goto ERROR_K
echo �h���C�u �j�F�� %DRIVE_K% �ɐݒ肵�܂����B

IF "%GHS_SH%"=="" SET GHS_SH=C:\green\ide\sh.501
IF "%CYGWIN%"=="" SET CYGWIN=C:\cygwin\bin
IF "%MINGW%"=="" SET MINGW=C:\mingw\bin
IF "%CFG%"=="" SET CFG=K:\cfg
SET PATH=%O_PATH%%GHS_SH%;%MINGW%;%CYGWIN%;%CFG%;
:echo PATH��GHS,CYGWIN,CFG��ǉ����܂����B

SET DRIVE_T=C:\TOPPERS\std_test
IF "%DEFAULT_BLD%"=="" SET DEFAULT_BLD=%DRIVE_T%\test\default%FULL_TEST%.bld

IF NOT "%2"=="bld" GOTO END
IF NOT "%3"=="-all" GOTO N3
IF exist %CFG%\cfg.exe GOTO N3
del library\libkernel.a 2>nul
pushd %CFG%
make depend
make cfg
popd

:N3
echo %1�̃J�[�l�����쐬���܂��B
pushd library
build -noreasons %3 default.bld
popd
GOTO END

:ERROR_K
echo �h���C�u �j�F���g�p�ł��܂���B
GOTO END

:ERROR1
echo.
echo setup.bat �̃p�����[�^���ԈႢ�ł�
:ERROR0
echo "setup j|f [bld [-all]]"
echo.
:END
