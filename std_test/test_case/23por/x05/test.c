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
#define _LAST_STEP 39
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
	ER_UINT rmsgsz ;
									_CHECK_STEP( 26 ) ;
	ercd = tcal_por( POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 , TMO_1 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
wup_tsk (TASK_ID3) ;
									_CHECK_STEP( 28 ) ;
	rmsgsz = cal_por( POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_RLWAI( rmsgsz ) ;

}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	ER_UINT rmsgsz ;
									_CHECK_STEP( 34 ) ;
	rmsgsz = cal_por( POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 ) ;

									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_DLT( rmsgsz ) ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cal_por( ERR_POR_ID, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = cal_por( POR_ID1, RDVPTN_0, rdv_msg1, sizeof(rdv_msg1)-1 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 5 ) ;
#ifdef ERR_POINTER
	ercd = cal_por( POR_ID1, RDVPTN_1, ERR_POINTER, sizeof(rdv_msg1)-1 ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 6 ) ;
#endif
									_CHECK_STEP( 7 ) ;
#ifdef ERR_CMSGSZ
	ercd = cal_por( POR_ID1, RDVPTN_1, rdv_msg1, ERR_CMSGSZ ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
#endif
									_CHECK_STEP( 9 ) ;
	ercd = cal_por( E_POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 11 ) ;
	ercd = tcal_por( ERR_POR_ID, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1, TMO_10 ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 13 ) ;
	ercd = tcal_por( POR_ID1, RDVPTN_0, rdv_msg1, sizeof(rdv_msg1)-1, TMO_10 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 15 ) ;
#ifdef ERR_POINTER
	ercd = tcal_por( POR_ID1, RDVPTN_1, ERR_POINTER, sizeof(rdv_msg1)-1, TMO_10 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 16 ) ;
#endif
									_CHECK_STEP( 17 ) ;
#ifdef ERR_CMSGSZ
	ercd = tcal_por( POR_ID1, RDVPTN_1, rdv_msg1, ERR_CMSGSZ, TMO_10 ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 18 ) ;
#endif
									_CHECK_STEP( 19 ) ;
	ercd = tcal_por( E_POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1, ERR_TMO ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = tcal_por( E_POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1, TMO_POL ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = tcal_por( E_POR_ID1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1, TMO_10 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 25 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
slp_tsk();
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	ercd = rel_wai(TASK_ID1 ) ;

									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = del_por( POR_ID1 ) ;

									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ext_tsk() ;
}
