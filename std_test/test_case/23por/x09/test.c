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
#define _LAST_STEP 45
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
	ER_UINT cmsgsz ;
	VB msg[RDVMSZ];
	RDVNO	rdvno;
									_CHECK_STEP( 13 ) ;
	cmsgsz = acp_por( POR_ID1, RDVPTN_1, &rdvno, msg) ;
_PRINT_VER( rdvno ) ;
									_CHECK_STEP( 28 ) ;
	ercd = ref_rdv( rdvno, &k_rrdv ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT( k_rrdv.wtskid == TASK_ID2 ) ;
									_CHECK_STEP( 31 ) ;
#ifdef ERR_POINTER
	pk_rpor = ERR_POINTER ;
									_CHECK_STEP( 32 ) ;
	ercd = ref_rdv( rdvno, pk_rrdv ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 32 ) ;
									_CHECK_STEP( 33 ) ;
#endif
									_CHECK_STEP( 34 ) ;
	ercd = ref_rdv( ERR_RDVNO, &k_rrdv ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( k_rrdv.wtskid == TSK_NONE ) ;
									_CHECK_STEP( 37 ) ;

	ercd = rpl_rdv( rdvno, rdv_msg2, sizeof(rdv_msg2)-1 ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	slp_tsk() ;

									_CHECK_STEP( 41 ) ;
	ercd = ref_rdv( rdvno, &k_rrdv ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT( k_rrdv.wtskid == TSK_NONE ) ;
									_CHECK_STEP( 44 ) ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	ER_UINT rmsgsz ;
									_CHECK_STEP( 16 ) ;
	rmsgsz = cal_por( POR_ID2, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 ) ;

									_CHECK_STEP( 27 ) ;
	rmsgsz = cal_por( POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 ) ;

}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	ER_UINT rmsgsz ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_por( ERR_POR_ID, &k_rpor ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rpor = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_por( POR_ID1, pk_rpor ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_por( E_POR_ID1, &k_rpor ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_por( POR_ID1, &k_rpor ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rpor.ctskid == TSK_NONE ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rpor.atskid == TSK_NONE ) ;
									_CHECK_STEP( 12 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;

	ercd = ref_por( POR_ID1, &k_rpor ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( k_rpor.ctskid == TSK_NONE ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( k_rpor.atskid == TASK_ID1 ) ;
									_CHECK_STEP( 22 ) ;

	ercd = ref_por( POR_ID2, &k_rpor ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( k_rpor.ctskid == TASK_ID2 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT( k_rpor.atskid == TSK_NONE ) ;
									_CHECK_STEP( 26 ) ;
	ercd = rel_wai(TASK_ID2 ) ;

									_CHECK_STEP( 40 ) ;
	wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 45 ) ;
	ext_tsk() ;
}

