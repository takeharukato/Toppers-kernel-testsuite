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
#define _LAST_STEP 49
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB stk[STKSZ];

T_CTSK k_ctsk1 = { TA_HLNG        , EXINF_1, TASK1,  ITSKPRI_1, STKSZ, NULL };
T_CTSK k_ctsk2 = { TA_HLNG|TA_ACT , EXINF_2, TASK2,  ITSKPRI_2, STKSZ, stk };
T_CTSK e_ctsk1 = { TA_HLNG        , EXINF_1, TASK16, ITSKPRI_3, STKSZ/8, NULL };

ER_ID tskid1=2,tskid2=3;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 25 ) ;
	p_stk = _read_sp() ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT( is_bufmgr_buffer( p_stk ) == TRUE ) ;
									_CHECK_STEP( 27 ) ;
	actcnt = can_act( TSK_SELF ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( actcnt == 0 ) ;
									_CHECK_STEP( 29 ) ;
	ercd = ras_tex( TSK_SELF, RASPTN_1 ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	VP p_stk;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( exinf == EXINF_2 ) ;
									_CHECK_STEP( 35 ) ;
	p_stk = _read_sp() ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( p_stk > stk && p_stk < &stk[STKSZ] ) ;
									_CHECK_STEP( 37 ) ;
	ercd = get_pri( TSK_SELF, p_tskpri ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( tskpri == ITSKPRI_2 ) ;
									_CHECK_STEP( 40 ) ;
	wupcnt = can_wup( TSK_SELF ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT( wupcnt == 0 ) ;
									_CHECK_STEP( 42 ) ;
	ercd = rsm_tsk( tskid2 ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 44 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	INT tskid_count = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_ctsk = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_tsk( pk_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.tskatr = ERR_TASKATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_POINTER
	k_ctsk = e_ctsk1 ;
	k_ctsk.task = ERR_POINTER ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.itskpri = ERR_ITSKPRI ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;
	k_ctsk = e_ctsk1 ;
	k_ctsk.stksz = ERR_STKSZ ;
									_CHECK_STEP( 14 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
	if ( ercd > 0 ) tskid_count++;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT( MERCD( ercd ) == E_PAR || MERCD( ercd ) == E_NOMEM) ;
									_CHECK_STEP( 16 ) ;
#ifdef ERR_POINTER
	k_ctsk = e_ctsk1 ;
	k_ctsk.stk = ERR_POINTER ;
									_CHECK_STEP( 17 ) ;
	ercd = acre_tsk( &k_ctsk ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 17 ) ;
									_CHECK_STEP( 18 ) ;
#endif
									_CHECK_STEP( 19 ) ;
	tskid1 = acre_tsk( &k_ctsk1 ) ;
	if ( tskid1 > 0 ) tskid_count++;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( tskid1 == 2 ) ;
_PRINT_VER( tskid1 ) ;
									_CHECK_STEP( 21 ) ;
	ercd = get_pri( tskid1, p_tskpri ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = act_tsk( tskid1 ) ;

									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	tskid2 = acre_tsk( &k_ctsk2 ) ;
	if ( tskid2 > 0 ) tskid_count++;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( tskid2 == 3 ) ;
_PRINT_VER( tskid2 ) ;
									_CHECK_STEP( 46 ) ;
	k_ctsk = e_ctsk1 ;
									_CHECK_STEP( 47 ) ;
	while ( tskid_count <= ACRE_CNT ) {
		ercd = acre_tsk( &k_ctsk ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) tskid_count++;
		else break;
	}
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ext_tsk() ;
}

void TASK16(VP_INT exinf)
{
	ext_tsk() ;
}
