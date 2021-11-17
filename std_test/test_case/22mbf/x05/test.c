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
#define _LAST_STEP 99
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB snd_buf[MBFSZ_256];
VB rcv_buf[MBFSZ_256];

void TASK1(VP_INT exinf)
{
	ER ercd ;
	ER_UINT msgsz ;
									_CHECK_STEP( 59 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 67 ) ;
	msgsz = rcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 73 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 81 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;

									_CHECK_STEP( 84 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 85 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 94 ) ;
	_CHECK_ASSERT_E_DLT( msgsz ) ;
									_CHECK_STEP( 95 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	ER_UINT msgsz ;
									_CHECK_STEP( 56 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 63 ) ;
	msgsz = rcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 71 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 75 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;
									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 77 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;

									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 89 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 91 ) ;
	_CHECK_ASSERT_E_RLWAI( msgsz ) ;
									_CHECK_STEP( 92 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	ER_UINT msgsz ;
	INT count;
									_CHECK_STEP( 1 ) ;
	ercd = snd_mbf( ERR_MBF_ID, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = psnd_mbf( ERR_MBF_ID, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 5 ) ;
	ercd = tsnd_mbf( ERR_MBF_ID, snd_buf, MSGSZ_10, TMO_POL ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 7 ) ;
	ercd = snd_mbf( E_MBF_ID1, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 9 ) ;
	ercd = psnd_mbf( E_MBF_ID1, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 11 ) ;
	ercd = tsnd_mbf( E_MBF_ID1, snd_buf, MSGSZ_10, TMO_POL ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 13 ) ;
#ifdef ERR_POINTER
	ercd = snd_mbf( MBF_ID1, ERR_POINTER, MSGSZ_10 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = psnd_mbf( MBF_ID1, ERR_POINTER, MSGSZ_10 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = tsnd_mbf( MBF_ID1, ERR_POINTER, MSGSZ_10, TMO_POL ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 14 ) ;
									_CHECK_STEP( 15 ) ;
									_CHECK_STEP( 16 ) ;
									_CHECK_STEP( 17 ) ;
									_CHECK_STEP( 18 ) ;
#endif
									_CHECK_STEP( 19 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_0 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = psnd_mbf( MBF_ID1, snd_buf, MSGSZ_0 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = tsnd_mbf( MBF_ID1, snd_buf, MSGSZ_0, TMO_POL ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 25 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_256 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = psnd_mbf( MBF_ID1, snd_buf, MSGSZ_256 ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = tsnd_mbf( MBF_ID1, snd_buf, MSGSZ_256, TMO_POL ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = tsnd_mbf( MBF_ID1, snd_buf, MSGSZ_10, ERR_TMO ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 33 ) ;

	ercd = rcv_mbf( ERR_MBF_ID, rcv_buf ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = prcv_mbf( ERR_MBF_ID, rcv_buf ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = trcv_mbf( ERR_MBF_ID, rcv_buf, TMO_POL ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 39 ) ;
#ifdef ERR_POINTER
	ercd = rcv_mbf( MBF_ID1, ERR_POINTER ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 41 ) ;
	ercd = prcv_mbf( MBF_ID1, ERR_POINTER ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 43 ) ;
	ercd = trcv_mbf( MBF_ID1, ERR_POINTER ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 40 ) ;
									_CHECK_STEP( 41 ) ;
									_CHECK_STEP( 42 ) ;
									_CHECK_STEP( 43 ) ;
									_CHECK_STEP( 44 ) ;
#endif
									_CHECK_STEP( 45 ) ;
	ercd = trcv_mbf( MBF_ID1, snd_buf, ERR_TMO ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = rcv_mbf( E_MBF_ID1, snd_buf ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 49 ) ;

	for (count = 0 ;  count < MBFSZ_256/MSGSZ_10 ; count++) {
		memset( snd_buf, 'a'+count, MSGSZ_10 ) ;
		ercd = psnd_mbf( MBF_ID1, snd_buf, MSGSZ_10 ) ;
		if ( ercd == E_TMOUT ) break;
		}
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT( count < MBFSZ_256/MSGSZ_10 ) ;
_PRINT_VER( count ) ;
									_CHECK_STEP( 52 ) ;
	for (count = 0 ;  count < MBFSZ_256/MSGSZ_10 ; count++) {
		ercd = prcv_mbf( MBF_ID1, rcv_buf ) ;
		if ( ercd == E_TMOUT ) break;
_PRINT_VER( ercd ) ;
		if ( ercd != MSGSZ_10 ) break;
		if ('a'+count != *rcv_buf ) break;
		}
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT( 0 < count && count < MBFSZ_256/MSGSZ_10 ) ;
_PRINT_VER( count ) ;
									_CHECK_STEP( 55 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 79 ) ;
	ercd = wup_tsk(TASK_ID1 ) ;

									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	msgsz = prcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 86 ) ;
	_CHECK_ASSERT( msgsz == MAXMSZ ) ;
									_CHECK_STEP( 87 ) ;
	msgsz = prcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 90 ) ;
	rel_wai( TASK_ID2 ) ;

									_CHECK_STEP( 93 ) ;
	ercd = del_mbf( MBF_ID1 ) ;

									_CHECK_STEP( 96 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 97 ) ;
	ercd = del_mbf( MBF_ID2 ) ;
									_CHECK_STEP( 98 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 99 ) ;
	ext_tsk() ;
}

