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

#define _TEST_TIME 3
#define _LAST_STEP 34
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_DOVR k_dovr1 = { TA_HLNG,   OVRHDR_1   } ;
T_DOVR k_dovr2 = { TA_HLNG,   OVRHDR_2   } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;

									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_dovr = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = def_ovr( pk_dovr ) ;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_dovr = k_dovr1 ;
	k_dovr.ovratr = ERR_OVRATR ;
									_CHECK_STEP( 5 ) ;
	ercd = def_ovr( &k_dovr ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_POINTER
	k_dovr = k_dovr1 ;
	k_dovr.ovrhdr =  ERR_POINTER ;
									_CHECK_STEP( 8 ) ;
	ercd = def_ovr( &k_dovr ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
	ercd = def_ovr( &k_dovr1 ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 12 ) ;
	ovr_work1 = ovr_work2 = 0 ;
									_CHECK_STEP( 13 ) ;
	ercd = sta_ovr( TASK_ID1, OVRTIM_1000 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = sta_ovr( TASK_ID2, OVRTIM_50 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT( ovr_work1 == 0 ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT( ovr_work2 == 0 ) ;
									_CHECK_STEP( 19 ) ;
	ercd = act_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 26 ) ;
	ercd = def_ovr( &k_dovr2 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = def_ovr( &k_dovr1 ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;

									_CHECK_STEP( 31 ) ;

									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( ovr_work1 == 0 ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( ovr_work2 == 1 ) ;
									_CHECK_STEP( 35 ) ;
	pk_dovr = NULL ;
									_CHECK_STEP( 36 ) ;
	ercd = def_ovr( pk_dovr ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( ovr_work1 == 0 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( ovr_work2 == 0 ) ;
									_CHECK_STEP( 24 ) ;
	while (ovr_work2 == 0) {

		}
									_CHECK_STEP( 25 ) ;
	ercd = wup_tsk (TASK_ID1 ) ;
	ext_tsk() ;
}

void OVRHDR_1( ID tskid, VP_INT exinf )
{

	if(( tskid == TASK_ID1 )  &&
		( exinf == EXINF_1 ))
		ovr_work1++;
	if(( tskid == TASK_ID2 )  &&
		( exinf == EXINF_2 ))
		ovr_work2++;
}

void OVRHDR_2( ID tskid, VP_INT exinf )
{

	if(( tskid == TASK_ID1 )  &&
		( exinf == EXINF_1 ))
		ovr_work11++;
	if(( tskid == TASK_ID2 )  &&
		( exinf == EXINF_2 ))
		ovr_work12++;
}

