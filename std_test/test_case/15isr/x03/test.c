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
#define _LAST_STEP 18
#define _NEED_TEST_ROUTINES
#include "test_com.h"
#include "hw_routines.h"

void dummy();

T_CISR k_cisr1 = { TA_HLNG , EXINF_1 , INTNO_1 , ISR_1  } ;
T_CISR e_cisr1 = { TA_HLNG , EXINF_1 , INTNO_1 , (FP)dummy  } ;

ER_ID isr_id1 ;

void TASK1(VP_INT exinf)
{
	ER ercd;
	UINT  isrid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cisr = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_isr( pk_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cisr = e_cisr1 ;
	k_cisr.isratr = ERR_ISRATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_isr( &k_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_INTNO
	k_cisr = e_cisr1 ;
	k_cisr.intno = ERR_INTNO ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_isr( &k_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
#ifdef ERR_POINTER
	k_cisr = e_cisr1 ;
	k_cisr.isrhdr =  ERR_POINTER ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_isr( &k_cisr ) ;
	if ( ercd > 0 ) isrid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 11 ) ;
									_CHECK_STEP( 12 ) ;
#endif
									_CHECK_STEP( 13 ) ;

	isr_id1 = acre_isr( &k_cisr1 ) ;
	if ( isr_id1 > 0 ) isrid_cnt++;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT( isr_id1 > 0 ) ;
									_CHECK_STEP( 15 ) ;
//	RAISE_INTERRUPT() ;
									_CHECK_STEP( 16 ) ;
	while ( isrid_cnt <= ACRE_CNT ) {
		ercd = acre_isr( &k_cisr1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) isrid_cnt++;
		else break;
		}
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ext_tsk() ;
}

void ISR_1(VP_INT exinf)
{
	_CHECK_ASSERT( exinf == EXINF_1 ) ;
}

void dummy( VP_INT exinf )
{
}
