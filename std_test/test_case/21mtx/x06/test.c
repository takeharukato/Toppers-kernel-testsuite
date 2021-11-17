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
#define _LAST_STEP 54
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CMTX k_cmtx1 = { TA_TFIFO,    0   } ;


void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 35 ) ;
	ercd = loc_mtx( MTX_ID3) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	ercd = unl_mtx( MTX_ID3 ) ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 32 ) ;
	ercd = loc_mtx( MTX_ID3) ;
									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 48 ) ;
	ercd = unl_mtx( MTX_ID3 ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 27 ) ;
	ercd = loc_mtx( MTX_ID3 ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 42 ) ;
	ercd = unl_mtx( MTX_ID3 ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_mtx( ERR_MTX_ID, &k_rmtx ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rmtx = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_mtx( MTX_ID2, pk_rmtx ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_mtx( MTX_ID1, &k_rmtx ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_mtx( MTX_ID2, &k_rmtx ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rmtx.htskid == TSK_NONE ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rmtx.wtskid == TSK_NONE ) ;
									_CHECK_STEP( 12 ) ;
	ercd = cre_mtx( MTX_ID1, &k_cmtx1 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	ercd = ploc_mtx( MTX_ID1 ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 16 ) ;
	ercd = ref_mtx( MTX_ID1, &k_rmtx ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT( k_rmtx.htskid == TASK_ID4 ) ;
_PRINT_VER( k_rmtx.htskid ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( k_rmtx.wtskid == TSK_NONE ) ;
									_CHECK_STEP( 20 ) ;
	ercd = unl_mtx( MTX_ID1 ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 22 ) ;
	ercd = ref_mtx( MTX_ID1, &k_rmtx ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( k_rmtx.htskid == TSK_NONE ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT( k_rmtx.wtskid == TSK_NONE ) ;
									_CHECK_STEP( 26 ) ;
	ercd = act_tsk( TASK_ID3 ) ;

									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = ref_mtx( MTX_ID3, &k_rmtx ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( k_rmtx.htskid == TASK_ID3 ) ;
_PRINT_VER( k_rmtx.htskid ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( k_rmtx.wtskid == TASK_ID1 ) ;
_PRINT_VER( k_rmtx.wtskid ) ;
									_CHECK_STEP( 41 ) ;
	ercd = rel_wai( TASK_ID3 ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	ext_tsk() ;
}
