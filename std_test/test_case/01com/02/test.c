/* TOPPERS�J�[�l���e�X�g�X�C�[�g
 * 
 *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 *
 *  @(#) $Id: test.c,v 1.0 2004/04/22 00:00:00 morita Exp $
 */

#include <kernel.h>
#include "test.h"
#include "kernel_id.h"

#include <stdio.h>

#define _TEST_TIME 2  
#define _LAST_STEP 35
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;

	                                                                _CHECK_STEP( 1 ) ;
	/* msg1-msg16 is static variables */
									_CHECK_STEP( 2 ) ;
	msg16.msgpri = MSGPRI_16 ;
									_CHECK_STEP( 3 ) ;
	ercd = snd_mbx( MBX_ID1, &msg16 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 5 ) ;
	msg8.msgpri = MSGPRI_8 ;
									_CHECK_STEP( 6 ) ;
	ercd = snd_mbx( MBX_ID1, &msg8 ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 8 ) ;
	msg1.msgpri = MSGPRI_1 ;
									_CHECK_STEP( 9 ) ;
	ercd = snd_mbx( MBX_ID1, &msg1 ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 11 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
									_CHECK_STEP( 12 ) ;

	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
									_CHECK_STEP( 13 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
									_CHECK_STEP( 14 ) ;
	ext_tsk() ;
}

void TASK5(VP_INT exinf)
{
									_CHECK_STEP( 15 ) ;
	ext_tsk() ;
}

void TASK6(VP_INT exinf)
{
									_CHECK_STEP( 16 ) ;
	ext_tsk() ;
}

void TASK7(VP_INT exinf)
{
									_CHECK_STEP( 17 ) ;
	ext_tsk() ;
}

void TASK8(VP_INT exinf)
{
									_CHECK_STEP( 18 ) ;
	ext_tsk() ;
}

void TASK9(VP_INT exinf)
{
									_CHECK_STEP( 19 ) ;
	ext_tsk() ;
}

void TASK10(VP_INT exinf)
{
									_CHECK_STEP( 20 ) ;
	ext_tsk() ;
}

void TASK11(VP_INT exinf)
{
									_CHECK_STEP( 21 ) ;
	ext_tsk() ;
}

void TASK12(VP_INT exinf)
{
									_CHECK_STEP( 22 ) ;
	ext_tsk() ;
}

void TASK13(VP_INT exinf)
{
									_CHECK_STEP( 23 ) ;
	ext_tsk() ;
}

void TASK14(VP_INT exinf)
{
									_CHECK_STEP( 24 ) ;
	ext_tsk() ;
}

void TASK15(VP_INT exinf)
{
									_CHECK_STEP( 25 ) ;
	ext_tsk() ;
}

void TASK16(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 26 ) ;
	ercd = prcv_mbx( MBX_ID1, &pk_msg ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( pk_msg == &msg1 ) ;
									_CHECK_STEP( 29 ) ;
	ercd = prcv_mbx( MBX_ID1, &pk_msg ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( pk_msg == &msg8 ) ;
									_CHECK_STEP( 32 ) ;
	ercd = prcv_mbx( MBX_ID1, &pk_msg ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( pk_msg == &msg16 ) ;
									_CHECK_STEP( 35  ) ;
	ext_tsk() ;
}

