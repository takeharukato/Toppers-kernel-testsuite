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
#include "test_x02.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 58
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CSEM k_csem1 = { TA_TFIFO, ISEMCNT_2,    MAXSEM_2    } ;
T_CSEM k_csem2 = { TA_TPRI,  ISEMCNT_1,    MAXSEM_2    } ;

ER_ID semid1,semid2;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 38 ) ;
	ercd = wai_sem( semid1 ) ;

									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
	ercd = wai_sem( semid2 ) ;

									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 35 ) ;
	ercd = wai_sem( semid1 ) ;

									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = wai_sem( semid2 ) ;

									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	UINT  semid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_csem = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_sem( pk_csem ) ;
	if ( ercd > 0 ) semid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_csem = k_csem1 ;
	k_csem.sematr = ERR_SEMATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_sem( &k_csem ) ;
	if ( ercd > 0 ) semid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
	k_csem = k_csem1 ;
	k_csem.isemcnt = MAXSEM_2 + 1;
									_CHECK_STEP( 8 ) ;
	ercd = acre_sem( &k_csem ) ;
	if ( ercd > 0 ) semid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 10 ) ;
	k_csem = k_csem1 ;
	k_csem.maxsem = TMAX_MAXSEM + 1 ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_sem( &k_csem ) ;
	if ( ercd > 0 ) semid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;
	k_csem = k_csem1 ;
	k_csem.maxsem = 0 ;
									_CHECK_STEP( 14 ) ;
	ercd = acre_sem( &k_csem ) ;
	if ( ercd > 0 ) semid_cnt++;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 16 ) ;
	semid1 = acre_sem( &k_csem1 ) ;
_PRINT_VER( semid1 ) ;
	if ( semid1 > 0 ) semid_cnt++;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT( semid1 > 0 ) ;
									_CHECK_STEP( 18 ) ;
	ercd = sig_sem( semid1 ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT_E_QOVR( ercd ) ;
									_CHECK_STEP( 20 ) ;
	ercd = wai_sem( semid1 ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 22 ) ;
	ercd = pol_sem( semid1 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	ercd = pol_sem( semid1 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 26 ) ;
	ercd = sig_sem( semid1 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = pol_sem( semid1 ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	semid2 = acre_sem( &k_csem2 ) ;
_PRINT_VER( semid2 ) ;
	if ( semid2 > 0 ) semid_cnt++;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( semid2 > 0 ) ;
									_CHECK_STEP( 32 ) ;
	ercd = pol_sem( semid2 ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = sig_sem( semid1 ) ;

									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	ercd = sig_sem( semid1 ) ;

									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 48 ) ;
	ercd = sig_sem( semid2 ) ;

									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ercd = sig_sem( semid2 ) ;

									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 56 ) ;
	while ( semid_cnt <= ACRE_CNT ) {
		ercd = acre_sem( &k_csem2 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) semid_cnt++;
		else break;
		}
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ext_tsk() ;
}

