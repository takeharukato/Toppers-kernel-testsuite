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
#define _LAST_STEP 69
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = rot_rdq( ERR_TSKPRI ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = get_tid( p_tskid ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT( tskid == TASK_ID1 ) ;
									_CHECK_STEP( 6 ) ;
	state = sns_dpn() ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 8 ) ;
	ercd = loc_cpu() ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	state = sns_loc() ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 12 ) ;
	state = sns_dpn() ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 14 ) ;
	ercd = loc_cpu() ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 16 ) ;
	state = sns_loc() ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 18 ) ;
	ercd = unl_cpu() ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 20 ) ;
	state = sns_loc() ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 22 ) ;
	ercd = unl_cpu() ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	state = sns_loc() ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 26 ) ;
	state = sns_ctx() ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 28 ) ;
	ercd = dis_dsp() ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 32 ) ;
	state = sns_dpn() ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 34 ) ;
	ercd = dis_dsp() ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( state == TRUE ) ;
									_CHECK_STEP( 38 ) ;
	ercd = ena_dsp() ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 42 ) ;
	ercd = ena_dsp() ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	state = sns_dsp() ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 46 ) ;
	ercd = rot_rdq( TPRI_SELF ) ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = chg_pri( TASK_ID2, TSKPRI_2 ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = chg_pri( TASK_ID3, TSKPRI_2 ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = chg_pri( TASK_ID4, TSKPRI_2 ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ercd = rot_rdq( TSKPRI_2 ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ercd = rot_rdq( TSKPRI_2 ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ercd = dly_tsk( DLYTIM_20 ) ;
									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 47 ) ;
	ercd = rot_rdq( TSKPRI_1 ) ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 48 ) ;
	ercd = rot_rdq( TPRI_SELF ) ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 67 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 49 ) ;
	ercd = rot_rdq( TSKPRI_1 ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	ext_tsk() ;
}

