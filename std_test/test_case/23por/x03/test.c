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
#include "test_x03.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 33
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CPOR k_cpor1 = { TA_TFIFO,    BLKSZ_256, BLKSZ_256  } ;
ER_ID  por_id1;

void TASK1(VP_INT exinf)
{
	ER ercd ;
	ER_UINT cmsgsz ;
	VB msg[RDVMSZ];
	RDVNO	rdvno;
									_CHECK_STEP( 16 ) ;
	cmsgsz = acp_por( por_id1, RDVPTN_1, &rdvno, msg) ;
_PRINT_VER( rdvno ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( cmsgsz == sizeof(rdv_msg1)-1 ) ;
									_CHECK_STEP( 21 ) ;
	ercd = strncmp(msg, rdv_msg1, cmsgsz ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( ercd == 0 ) ;
									_CHECK_STEP( 23 ) ;
	ercd = rpl_rdv( rdvno, rdv_msg2, sizeof(rdv_msg2)-1 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 25 ) ;
	slp_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	ER_UINT rmsgsz ;
									_CHECK_STEP( 19 ) ;
	rmsgsz = cal_por( por_id1, RDVPTN_1, rdv_msg1, sizeof(rdv_msg1)-1 ) ;

									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT( rmsgsz == sizeof(rdv_msg2)-1 ) ;
									_CHECK_STEP( 27 ) ;
	ercd = strncmp(rdv_msg1, rdv_msg2, rmsgsz ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( ercd == 0 ) ;
									_CHECK_STEP( 29 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	UINT  porid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cpor = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_por( pk_cpor ) ;
	if ( ercd > 0 ) porid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cpor = k_cpor1 ;
	k_cpor.poratr = ERR_PORATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_por( &k_cpor ) ;
	if ( ercd > 0 ) porid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_MAXCMSZ
	k_cpor = k_cpor1 ;
	k_cpor.maxcmsz = ERR_MAXCMSZ ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_por( &k_cpor ) ;
	if ( ercd > 0 ) porid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
#ifdef ERR_MAXRMSZ
	k_cpor = k_cpor1 ;
	k_cpor.maxrmsz = ERR_MAXRMSZ ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_por( &k_cpor ) ;
	if ( ercd > 0 ) porid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 11 ) ;
									_CHECK_STEP( 12 ) ;
#endif
									_CHECK_STEP( 13 ) ;
	por_id1 = acre_por( &k_cpor1 ) ;
	if ( por_id1 > 0 ) porid_cnt++;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT( por_id1 > 0 ) ;
									_CHECK_STEP( 15 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	while ( porid_cnt <= ACRE_CNT ) {
		ercd = acre_por( &k_cpor1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) porid_cnt++;
		else break;
		}
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 33 ) ;



	ext_tsk() ;
}
