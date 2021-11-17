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

T_CMPF k_cmpf1 = { TA_TFIFO, BLKCNT_1, BLKSZ_10, NULL } ;
T_CMPF k_cmpf2 = { TA_TFIFO, BLKCNT_1, BLKSZ_10, NULL } ;
T_CMPF e_cmpf1 = { TA_TFIFO, BLKCNT_2048, BLKSZ_256, NULL } ;

VP blk_No17 ;
VP blk_No38 ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
	VP blk ;
									_CHECK_STEP( 51 ) ;
	ercd = get_mpf( MPF_ID1, &blk ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	VP blk ;
									_CHECK_STEP( 48 ) ;
	ercd = get_mpf( MPF_ID1, &blk ) ;
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT( blk == blk_No38 ) ;
									_CHECK_STEP( 59 ) ;
	ercd = rel_wai( TASK_ID1 ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	ercd = rel_mpf( MPF_ID1, blk ) ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	VP blk ;
									_CHECK_STEP( 45 ) ;
	ercd = get_mpf( MPF_ID1, &blk ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	blk_No38 = blk ;
									_CHECK_STEP( 56 ) ;
	ercd = rel_mpf( MPF_ID1, blk ) ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 67 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
	VP blk, *p_blk = &blk ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_mpf( ERR_MPF_ID, &k_cmpf1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_cmpf = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = cre_mpf( E_MPF_ID1, pk_cmpf ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	k_cmpf = k_cmpf1 ;
	k_cmpf.mpfatr = ERR_MPFATR ;
									_CHECK_STEP( 7 ) ;
	ercd = cre_mpf( E_MPF_ID2, &k_cmpf ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 9 ) ;
	k_cmpf = k_cmpf2 ;
	k_cmpf.blkcnt = BLKCNT_0 ;
									_CHECK_STEP( 10 ) ;
	ercd = cre_mpf( E_MPF_ID3, &k_cmpf ) ;
									_CHECK_STEP( 11 ) ;
	if (MERCD( ercd ) == E_OK ) {
									_CHECK_STEP( 12 ) ;
		ercd = pget_mpf( E_MPF_ID3, &blk ) ;
									_CHECK_STEP( 13 ) ;
		_CHECK_ASSERT( MERCD( ercd ) != E_OK ) ;
	}
	else {
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;
	}
									_CHECK_STEP( 14 ) ;
	k_cmpf = k_cmpf2 ;
	k_cmpf.blksz = BLKSZ_0 ;
									_CHECK_STEP( 15 ) ;
	ercd = cre_mpf( E_MPF_ID4, &k_cmpf ) ;
									_CHECK_STEP( 16 ) ;
	if (MERCD( ercd ) == E_OK ) {
									_CHECK_STEP( 17 ) ;
		ercd = pget_mpf( E_MPF_ID4, &blk ) ;
									_CHECK_STEP( 18 ) ;
		_CHECK_ASSERT( MERCD( ercd ) != E_OK ) ;
	}
	else {
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 18 ) ;
	}
									_CHECK_STEP( 19 ) ;
#ifdef ERR_POINTER
	k_cmpf = k_cmpf2 ;
	k_cmpf.mpf =  ERR_POINTER ;
									_CHECK_STEP( 20 ) ;
	ercd = cre_mpf( E_MPF_ID5, &k_cmpf ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 20 ) ;
									_CHECK_STEP( 21 ) ;
#endif
									_CHECK_STEP( 22 ) ;
	ercd = cre_mpf( E_MPF_ID6, &e_cmpf1 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_NOMEM( ercd ) ;
									_CHECK_STEP( 24 ) ;
	ercd = cre_mpf( E_MPF_ID7, &k_cmpf1 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
	ercd = cre_mpf( E_MPF_ID7, &k_cmpf1 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = cre_mpf( MPF_ID1, &k_cmpf1 ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	ercd = cre_mpf( MPF_ID2, &k_cmpf2 ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;

	ercd = pget_mpf( MPF_ID1, &blk ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	blk_No17 = blk ;
									_CHECK_STEP( 35 ) ;
	ercd = rel_mpf( MPF_ID2, blk ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = pget_mpf( MPF_ID1, p_blk ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ercd = rel_mpf( MPF_ID1, blk ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 41 ) ;
	ercd = get_mpf( MPF_ID1, p_blk ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT( *p_blk == blk_No17 ) ;
									_CHECK_STEP( 44 ) ;
	ercd = act_tsk( TASK_ID3 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = act_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = rel_mpf( MPF_ID1, blk ) ;
									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	ext_tsk() ;
}

