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

#define _TEST_TIME 3
#define _LAST_STEP 27
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void dummy();

T_CALM k_calm1 = { TA_HLNG,  EXINF_1,  ALMHDR_1   } ;
T_CALM k_calm2 = { TA_HLNG,  EXINF_2,  ALMHDR_2   } ;
T_CALM e_calm1 = { TA_HLNG,  EXINF_2,  (FP)dummy  } ;

ER_ID alm_id1, alm_id2;

void TASK1(VP_INT exinf)
{
	ER ercd ;
	UINT  almid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_calm = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_alm( pk_calm ) ;
	if ( ercd > 0 ) almid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_calm = e_calm1 ;
	k_calm.almatr = ERR_ALMATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_alm( &k_calm ) ;
	if ( ercd > 0 ) almid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_POINTER
	k_calm = e_calm1 ;
	k_calm.almhdr =  ERR_POINTER ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_alm( &k_calm ) ;
	if ( ercd > 0 ) almid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
	alm_id1 = acre_alm( &k_calm1 ) ;
	if ( alm_id1 > 0 ) almid_cnt++;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( alm_id1 > 0 ) ;
									_CHECK_STEP( 12 ) ;
	alm_id2 = acre_alm( &k_calm2 ) ;
	if ( alm_id2 > 0 ) almid_cnt++;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT( alm_id2 > 0 ) ;
									_CHECK_STEP( 14 ) ;

	alm_work1 = alm_work2 = 0 ;
									_CHECK_STEP( 15 ) ;
	ercd = sta_alm( alm_id2, DLYTIM_50 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = dly_tsk( DLYTIM_100 ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( alm_work2 == 1 ) ;
									_CHECK_STEP( 20 ) ;

	ercd = sta_alm( alm_id1, DLYTIM_100 ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 22 ) ;
	ercd = dly_tsk( DLYTIM_100 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( alm_work1 == 1 ) ;
									_CHECK_STEP( 25 ) ;
	while ( almid_cnt <= ACRE_CNT ) {
		ercd = acre_alm( &k_calm1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) almid_cnt++;
		else break;
		}
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ext_tsk() ;
}

void ALMHDR_1( VP_INT exinf )
{
	_CHECK_ASSERT( exinf == EXINF_1 ) ;
	alm_work1++ ;
	return ;
}

void ALMHDR_2( VP_INT exinf )
{
	_CHECK_ASSERT( exinf == EXINF_2 ) ;
	alm_work2++ ;
	return ;
}

void dummy( VP_INT exinf )
{
	return ;
}

