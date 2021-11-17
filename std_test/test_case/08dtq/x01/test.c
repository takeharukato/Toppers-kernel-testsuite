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
#define _LAST_STEP 93
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB DTQ1[TSZ_DTQ(DTQCNT_2)] ;

T_CDTQ k_cdtq1 = { TA_TFIFO, DTQCNT_1, NULL } ;
T_CDTQ k_cdtq2 = { TA_TPRI , DTQCNT_1, NULL } ;
T_CDTQ k_cdtq3 = { TA_TPRI , DTQCNT_2, (VP)DTQ1 } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 33 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( data == MEMORY ) ;
									_CHECK_STEP( 43 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_22 ) ;

									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 64 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_DD ) ;

									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	ercd = snd_dtq( DTQ_ID3, DATA_11 ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 71 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 30 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( data == DATA_33 ) ;
									_CHECK_STEP( 38 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_33 ) ;

									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_EE ) ;

									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 76 ) ;
	ercd = snd_dtq( DTQ_ID3, DATA_22 ) ;
									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_dtq( ERR_DTQ_ID, &k_cdtq1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_cflg = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = cre_dtq( E_FLG_ID1, pk_cdtq ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqatr = ERR_DTQATR ;
									_CHECK_STEP( 7 ) ;
	ercd = cre_dtq( E_DTQ_ID2, &k_cdtq ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 9 ) ;
#ifdef ERR_DTQCNT
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqcnt = ERR_DTQCNT ;
									_CHECK_STEP( 10 ) ;
	ercd = cre_dtq( E_DTQ_ID3, &k_cdtq ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 10 ) ;
									_CHECK_STEP( 11 ) ;
#endif
									_CHECK_STEP( 12 ) ;
#ifdef ERR_POINTER
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtq = ERR_POINTER ;
									_CHECK_STEP( 13 ) ;
	ercd = cre_dtq( E_DTQ_ID4, &k_cdtq ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 13 ) ;
									_CHECK_STEP( 14 ) ;
#endif
									_CHECK_STEP( 15 ) ;
	ercd = cre_dtq( DTQ_ID1, &k_cdtq1 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = cre_dtq( DTQ_ID1, &k_cdtq1 ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 19 ) ;
	ercd = cre_dtq( DTQ_ID2, &k_cdtq2 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = cre_dtq( DTQ_ID3, &k_cdtq3 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_55 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 25 ) ;
	p_data = &data ;
									_CHECK_STEP( 26 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( data == DATA_55 ) ;
									_CHECK_STEP( 29 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_33 ) ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = snd_dtq( DTQ_ID1, MEMORY ) ;

									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 45 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_00 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = wup_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_FF ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT( data == DATA_00 ) ;
									_CHECK_STEP( 62 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( data == DATA_33 ) ;
									_CHECK_STEP( 67 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;

									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT( data == DATA_FF ) ;
									_CHECK_STEP( 74 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;

									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT( data == DATA_DD ) ;
									_CHECK_STEP( 81 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	_CHECK_ASSERT( data == DATA_EE ) ;
									_CHECK_STEP( 84 ) ;
	ercd = rcv_dtq( DTQ_ID3, p_data ) ;
									_CHECK_STEP( 85 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 86 ) ;
	_CHECK_ASSERT( data == DATA_11 ) ;
									_CHECK_STEP( 87 ) ;
	ercd = rcv_dtq( DTQ_ID3, p_data ) ;
									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 89 ) ;
	_CHECK_ASSERT( data == DATA_22 ) ;
									_CHECK_STEP( 90 ) ;
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqcnt = DTQCNT_MAX ;
_PRINT_VER( TSZ_DTQ( DTQCNT_MAX ) ) ;
									_CHECK_STEP( 91 ) ;
	ercd = cre_dtq( E_DTQ_ID5, &k_cdtq ) ;
									_CHECK_STEP( 92 ) ;
	_CHECK_ASSERT_E_NOMEM( ercd ) ;
									_CHECK_STEP( 93 ) ;
	ext_tsk() ;
}

