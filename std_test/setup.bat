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

if "%1"=="" goto END
goto %1

:SET_ENV
:: �f�o�b�O�T�[�o�̃I�v�V�������w��
::��Fhpserv���f�o�b�O�T�[�o�Ƃ��Ďw�肷�鎞��
::��΃p�X���w�肵�Ă��������B

:set ADV=adv007
set ADV=192.0.9.168
set MPV=dh630_7729_jpn.mpv
set CPU=SH7727
set INI=%BAT_DIR%init.setup

set DEBUG_SVR=%GHS_SH%\adpserv -H %ADV% -m%MPV% -c%CPU% -l -setup %INI%
set TIMEOUT_SVR=1
goto END

:DEL_ENV
set DEBUG_SVR=
set TIMEOUT_SVR=
set ADV=
set MPV=
set CPU=
set INI=
:END
