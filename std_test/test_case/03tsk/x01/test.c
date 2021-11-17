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
#define _LAST_STEP 52
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB stk[STKSZ];

T_CTSK k_ctsk1 = { TA_HLNG        , EXINF_1, TASK1,  ITSKPRI_1, STKSZ, NULL };
T_CTSK k_ctsk2 = { TA_HLNG|TA_ACT , EXINF_2, TASK2,  ITSKPRI_2, STKSZ, stk };
T_CTSK e_ctsk1 = { TA_HLNG        , EXINF_1, TASK16, ITSKPRI_16, STKSZ/8, NULL };

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 31 ) ;
	p_stk = _read_sp() ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT( is_bufmgr_buffer( p_stk ) == TRUE ) ;
									_CHECK_STEP( 33 ) ;
	actcnt = can_act( TSK_SELF ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( actcnt == 0 ) ;
									_CHECK_STEP( 35 ) ;
	ercd = ras_tex( TSK_SELF, RASPTN_1 ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	VP p_stk;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( exinf == EXINF_2 ) ;
									_CHECK_STEP( 41 ) ;
	p_stk = _read_sp() ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( p_stk > stk && p_stk < &stk[STKSZ] ) ;
									_CHECK_STEP( 43 ) ;
	ercd = get_pri( TSK_SELF, p_tskpri ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( tskpri == ITSKPRI_2 ) ;
									_CHECK_STEP( 46 ) ;
	wupcnt = can_wup( TSK_SELF ) ;
									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT( wupcnt == 0 ) ;
									_CHECK_STEP( 48 ) ;
	ercd = rsm_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_tsk( ERR_TASK_ID, &k_ctsk1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = cre_tsk( TSK_SELF, &k_ctsk1 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 5 ) ;
	ercd = cre_tsk( TASK_ID3, &k_ctsk1 ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_POINTER
	pk_ctsk = ERR_POINTER ;
									_CHECK_STEP( 8 ) ;
	ercd = cre_tsk( E_TASK_ID1, pk_ctsk ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.tskatr = ERR_TASKATR ;
									_CHECK_STEP( 11 ) ;
	ercd = cre_tsk( E_TASK_ID2, &k_ctsk ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 13 ) ;
#ifdef ERR_POINTER
	k_ctsk = e_ctsk1 ;
	k_ctsk.task = ERR_POINTER ;
									_CHECK_STEP( 14 ) ;
	ercd = cre_tsk( E_TASK_ID3, &k_ctsk ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 14 ) ;
									_CHECK_STEP( 15 ) ;
#endif
									_CHECK_STEP( 16 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.itskpri = ERR_ITSKPRI ;
									_CHECK_STEP( 17 ) ;
	ercd = cre_tsk( E_TASK_ID4, &k_ctsk ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 19 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.stksz = ERR_STKSZ ;
									_CHECK_STEP( 20 ) ;
	ercd = cre_tsk( E_TASK_ID5, &k_ctsk ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( MERCD( ercd ) == E_PAR || MERCD( ercd ) == E_NOMEM) ;
									_CHECK_STEP( 22 ) ;
#ifdef ERR_POINTER
	k_ctsk = e_ctsk1 ;
	k_ctsk.stk = ERR_POINTER ;
									_CHECK_STEP( 23 ) ;
	ercd = cre_tsk( E_TASK_ID6, &k_ctsk ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 23 ) ;
									_CHECK_STEP( 24 ) ;
#endif
									_CHECK_STEP( 25 ) ;
	ercd = cre_tsk( TASK_ID1, &k_ctsk1 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = get_pri( TASK_ID1, p_tskpri ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ercd = cre_tsk( TASK_ID2, &k_ctsk2 ) ;

									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ext_tsk() ;
}

void TASK16(VP_INT exinf)
{
	ext_tsk() ;
}
