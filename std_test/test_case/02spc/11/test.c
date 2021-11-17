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
#define _LAST_STEP 67
#define _NEED_TEST_ROUTINES
#include "test_com.h"
#include "hw_routines.h"

void TASK1(VP_INT exinf)
{
									_CHECK_STEP( 41 ) ;
	actcnt = can_act( TSK_SELF ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( actcnt == 1 ) ;
									_CHECK_STEP( 43 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	PREPARE_SW_DELAY( DLYTIM_20 ) ;
									_CHECK_STEP( 1 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 3 ) ;
	ercd = dis_dsp() ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 5 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 7 ) ;
	ercd = pol_sem( SEM_ID1 ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 9 ) ;
	ercd = get_tid( p_tskid ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( tskid == TASK_ID2 ) ;
									_CHECK_STEP( 12 ) ;
	ercd = loc_cpu() ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 16 ) ;
	ercd = unl_cpu() ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 20 ) ;
	RAISE_INTERRUPT() ;
									_CHECK_STEP( 22 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 24 ) ;
	ercd = sta_cyc( CYC_ID1 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
	SW_DELAY() ;
									_CHECK_STEP( 30 ) ;
	ercd = stp_cyc( CYC_ID1 ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 34 ) ;
	ercd = ena_tex() ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = ras_tex( TASK_ID2, RASPTN_2 ) ;
									_CHECK_STEP( 38 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 40 ) ;
	ercd = ena_dsp() ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 45 ) ;
	RAISE_INTERRUPT() ;
									_CHECK_STEP( 47 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 49 ) ;
	ercd = sta_cyc( CYC_ID1 ) ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = dly_tsk( DLYTIM_20 ) ;
									_CHECK_STEP( 52 ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 56 ) ;
	ercd = ras_tex( TASK_ID2, RASPTN_2 ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 61 ) ;
	ercd = loc_cpu() ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 65 ) ;
	ercd = unl_cpu() ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 67 ) ;
	ext_tsk() ;
}

void TEXRTN_2(TEXPTN texptn, VP_INT exinf)
{
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 37 ) ;
		return ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 57 ) ;
		return ;
	}
	else {
									_CHECK_STEP( -1 ) ;
		return ;
	}
}

void INTHDR_1( void )
{
	static int nCount = 0 ;
	CLEAR_INTERRUPT() ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 21 ) ;
		return ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 46 ) ;
		return ;
	}
	else {
									_CHECK_STEP( -1 ) ;
		return ;
	}
}

void CYCHDR_1(VP_INT exinf)
{
	ER ercd ;
	static int nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 27 ) ;
		ercd = iact_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 28 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
		return ;
	}
	else {
		return ;
	}
}

