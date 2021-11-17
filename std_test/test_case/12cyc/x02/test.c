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

#define _TEST_TIME 3
#define _LAST_STEP 42
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void dummy_hdr( VP_INT exinf )
{
}

T_CCYC k_ccyc1 = { TA_HLNG|TA_STA, EXINF_CYC1, CYCHDR_1, CYCTIM_10, CYCPHS_5   } ;
T_CCYC k_ccyc2 = { TA_HLNG|TA_PHS, EXINF_CYC2, CYCHDR_2, CYCTIM_55, CYCPHS_5   } ;
T_CCYC e_ccyc1 = { TA_HLNG       , EXINF_CYC1, (FP)dummy_hdr,CYCTIM_10, CYCPHS_0   } ;

T_RCYC k_rcyc1, k_rcyc2;
ER_ID cyc_id1, cyc_id2;

void TASK1(VP_INT exinf)
{
	ER ercd ;
	UINT  cycid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_ccyc = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_cyc( pk_ccyc ) ;
	if ( ercd > 0 ) cycid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_ccyc = e_ccyc1 ;
	k_ccyc.cycatr = ERR_CYCATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_cyc( &k_ccyc ) ;
	if ( ercd > 0 ) cycid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_POINTER
	k_ccyc = e_ccyc1 ;
	k_ccyc.cychdr =  ERR_POINTER ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_cyc( &k_ccyc ) ;
	if ( ercd > 0 ) cycid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
	k_ccyc = e_ccyc1 ;
	k_ccyc.cyctim =  0 ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_cyc( &k_ccyc ) ;
	if ( ercd > 0 ) cycid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;

	cyc_id1 = acre_cyc( &k_ccyc1 ) ;
	if ( cyc_id1 > 0 ) cycid_cnt++;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT( cyc_id1 > 0 ) ;
									_CHECK_STEP( 15 ) ;
	cyc_id2 = acre_cyc( &k_ccyc2 ) ;
	if ( cyc_id2 > 0 ) cycid_cnt++;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT( cyc_id2 > 0 ) ;
									_CHECK_STEP( 17 ) ;

	cyc_work1 = cyc_work2 = 0 ;
									_CHECK_STEP( 18 ) ;
	ercd = dly_tsk( DLYTIM_100 ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( cyc_work2 == 0 ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( cyc_work1 >= 9 ) ;
									_CHECK_STEP( 22 ) ;
	ercd = stp_cyc( cyc_id1 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	work = cyc_work1 ;
									_CHECK_STEP( 25 ) ;
	ercd = dly_tsk( DLYTIM_100 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT( cyc_work1 == work ) ;
									_CHECK_STEP( 28 ) ;

	ercd = sta_cyc( cyc_id2 ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	ercd = dly_tsk( CYCTIM_55 ) ;
work = cyc_work2 ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT( work == 1 ) ;
_PRINT_VER( work ) ;
									_CHECK_STEP( 33 ) ;

	ercd = sta_cyc( cyc_id2 ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;

	ercd = dly_tsk( CYCTIM_55 ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( cyc_work2 == 2  || cyc_work2 == 3 ) ;
									_CHECK_STEP( 38 ) ;
	ercd = stp_cyc( cyc_id2 ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	while ( cycid_cnt <= ACRE_CNT ) {
		ercd = acre_cyc( &k_ccyc1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) cycid_cnt++;
		else break;
		}
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ext_tsk() ;
}

void CYCHDR_1( VP_INT exinf )
{
	_CHECK_ASSERT( exinf == EXINF_CYC1 ) ;
	cyc_work1++ ;
	return ;
}

void CYCHDR_2( VP_INT exinf )
{
	_CHECK_ASSERT( exinf == EXINF_CYC2 ) ;
	cyc_work2++ ;
	return ;
}

