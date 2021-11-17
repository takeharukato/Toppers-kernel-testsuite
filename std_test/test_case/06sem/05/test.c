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

#define _TEST_TIME 2
#define _LAST_STEP 46
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 8 ) ;
		ercd = twai_sem( SEM_ID2, TMO_200 ) ;
									_CHECK_STEP( 11 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 12 ) ;
		ext_tsk() ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 23 ) ;
		ercd = twai_sem( SEM_ID2, TMO_FEVR ) ;
									_CHECK_STEP( 45 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
		ext_tsk() ;
	}
	else {
									_CHECK_STEP( -1 ) ;
	}
}

void TASK2_1(VP_INT exinf)
{
	ER ercd ;
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 2 ) ;
		ercd = twai_sem( SEM_ID2, TMO_100 ) ;
									_CHECK_STEP( 15 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 16 ) ;
		ext_tsk() ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 26 ) ;
		ercd = twai_sem( SEM_ID2, TMO_FEVR ) ;
									_CHECK_STEP( 42 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
		ercd = sig_sem( SEM_ID2 ) ;
									_CHECK_STEP( 44 ) ;
		ext_tsk() ;
	}
	else {
									_CHECK_STEP( -1 ) ;
	}
}

void TASK2_2(VP_INT exinf)
{
	ER ercd ;
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 5 ) ;
		ercd = twai_sem( SEM_ID2, TMO_FEVR ) ;
									_CHECK_STEP( 19 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 20 ) ;
		ext_tsk() ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 29 ) ;
		ercd = twai_sem( SEM_ID2, TMO_FEVR ) ;
									_CHECK_STEP( 39 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
		ercd = sig_sem( SEM_ID2 ) ;
									_CHECK_STEP( 41 ) ;
		ext_tsk() ;
	}
	else {
									_CHECK_STEP( -1 ) ;
	}
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = act_tsk( TASK_ID2_1 ) ;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 4 ) ;
	ercd = act_tsk( TASK_ID2_2 ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 7 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	ercd =sig_sem( SEM_ID2 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	ercd =sig_sem( SEM_ID2 ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ercd =sig_sem( SEM_ID2 ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 22 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 25 ) ;
	ercd = act_tsk( TASK_ID2_1 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = act_tsk( TASK_ID2_2 ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = chg_pri( TASK_ID1, ITSKPRI_4 ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	ercd = chg_pri( TASK_ID2_2, ITSKPRI_3 ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = chg_pri( TASK_ID2_1, ITSKPRI_3 ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd =sig_sem( SEM_ID2 ) ;
									_CHECK_STEP( 38 ) ;
	ext_tsk() ;
}

