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
#define _LAST_STEP 79
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 27 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 62 ) ;
	ercd = wup_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 64 ) ;
	ercd = ref_tsk( TASK_ID2, &k_rtsk ) ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( k_rtsk.wupcnt == 1 ) ;
									_CHECK_STEP( 67 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_tsk( ERR_TASK_ID, &k_rtsk ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rtsk = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_tsk( TASK_ID2, pk_rtsk ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_tsk( E_TASK_ID1, &k_rtsk ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_tsk( TSK_SELF, &k_rtsk ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	ercd = ref_tsk( TASK_ID3, &k_rtsk ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT( k_rtsk.tskstat == TTS_RDY ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT( k_rtsk.tskpri == ITSKPRI_3 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT( k_rtsk.tskbpri == ITSKPRI_3 ) ;
									_CHECK_STEP( 15 ) ;
	ercd = ref_tsk( TASK_ID2, &k_rtsk ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT( k_rtsk.tskstat == TTS_RUN ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT( k_rtsk.tskpri == ITSKPRI_2 ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( k_rtsk.tskbpri == ITSKPRI_2 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( k_rtsk.tskwait == 0 ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( k_rtsk.wobjid == 0 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( k_rtsk.lefttmo == 0 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( k_rtsk.actcnt == 0 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( k_rtsk.wupcnt == 0 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT( k_rtsk.suscnt == 0 ) ;
									_CHECK_STEP( 26 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = ref_tsk( TASK_ID1, &k_rtsk ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( k_rtsk.tskstat == TTS_WAI ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT( k_rtsk.tskpri == ITSKPRI_1 ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( k_rtsk.tskbpri == ITSKPRI_1 ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( k_rtsk.tskwait == TTW_SLP ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT( k_rtsk.wobjid == 0 ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( k_rtsk.lefttmo == 0 ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( k_rtsk.actcnt == 0 ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT( k_rtsk.wupcnt == 0 ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( k_rtsk.suscnt == 0 ) ;
									_CHECK_STEP( 40 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = ref_tsk( TASK_ID1, &k_rtsk ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT( k_rtsk.actcnt == 1 ) ;
									_CHECK_STEP( 45 ) ;
	ercd = sus_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = ref_tsk( TASK_ID1, &k_rtsk ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT( k_rtsk.tskstat == TTS_WAS ) ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT( k_rtsk.suscnt == 1 ) ;
									_CHECK_STEP( 51 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	actcnt = can_act ( TASK_ID1 ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT( actcnt == 1 ) ;
									_CHECK_STEP( 55 ) ;
	ercd = ref_tsk( TASK_ID1, &k_rtsk ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT( k_rtsk.tskstat == TTS_SUS ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT( k_rtsk.actcnt == 0 ) ;
									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT( k_rtsk.suscnt == 1 ) ;
									_CHECK_STEP( 60 ) ;
	ercd = rsm_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	ercd = ref_tsk( TASK_ID1, &k_rtsk ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT( k_rtsk.tskstat == TTS_DMT ) ;
									_CHECK_STEP( 72 ) ;
	ercd = dly_tsk ( DLYTIM_500 ) ;

									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 79 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 73 ) ;
	ercd = ref_tsk( TASK_ID2, &k_rtsk ) ;
									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT( k_rtsk.tskstat == TTS_WAI ) ;
									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT( k_rtsk.tskwait == TTW_DLY ) ;
									_CHECK_STEP( 77 ) ;
	ext_tsk() ;
}
