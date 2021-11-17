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
#define _LAST_STEP 59
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CDTQ k_cdtq1 = { TA_TFIFO, DTQCNT_0, NULL } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 19 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_EE ) ;

									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_EE ) ;

									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 45 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 16 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_DD ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_DD ) ;

									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_dtq( ERR_DTQ_ID, &k_rdtq ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rdtq = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_dtq( DTQ_ID2, pk_rdtq ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_dtq( DTQ_ID1, &k_rdtq ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_dtq( DTQ_ID2, &k_rdtq ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd );
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rdtq.stskid == TSK_NONE ) ;
_PRINT_VER( k_rdtq.stskid) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rdtq.rtskid == TSK_NONE ) ;
_PRINT_VER( k_rdtq.rtskid) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT( k_rdtq.sdtqcnt == 0 ) ;
_PRINT_VER( k_rdtq.sdtqcnt )
									_CHECK_STEP( 13 ) ;
	ercd = cre_dtq( DTQ_ID1, &k_cdtq1 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = ref_dtq( DTQ_ID1, &k_rdtq ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_OK( ercd );
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( k_rdtq.stskid == TASK_ID2 ) ;
_PRINT_VER( k_rdtq.stskid) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( k_rdtq.rtskid == TSK_NONE ) ;
_PRINT_VER( k_rdtq.rtskid) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT( k_rdtq.sdtqcnt == 0 ) ;
_PRINT_VER( k_rdtq.sdtqcnt )
									_CHECK_STEP( 26 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_FF ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_FF ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	ercd = rel_wai( TASK_ID2 ) ;

									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = rel_wai( TASK_ID1 ) ;

									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = ref_dtq( DTQ_ID2, &k_rdtq ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd );
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( k_rdtq.stskid == TASK_ID1 ) ;
_PRINT_VER( k_rdtq.stskid) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT( k_rdtq.rtskid == TSK_NONE ) ;
_PRINT_VER( k_rdtq.rtskid) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( k_rdtq.sdtqcnt == 2 ) ;
_PRINT_VER( k_rdtq.sdtqcnt )
									_CHECK_STEP( 43 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;

									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = ref_dtq( DTQ_ID1, &k_rdtq ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd );
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT( k_rdtq.stskid == TSK_NONE ) ;
_PRINT_VER( k_rdtq.stskid) ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT( k_rdtq.rtskid == TASK_ID1 ) ;
_PRINT_VER( k_rdtq.rtskid) ;
									_CHECK_STEP( 51 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;

									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd );
									_CHECK_STEP( 55 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_FF ) ;

									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ext_tsk() ;
}

