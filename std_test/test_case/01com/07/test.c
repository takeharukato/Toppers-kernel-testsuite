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
#define _LAST_STEP 83
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
									_CHECK_STEP( 1 ) ;
	_CHECK_ASSERT( 1 == sizeof(B) ) ;
									_CHECK_STEP( 2 ) ;
	b1 = -1 ;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT( b1 < 0 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT( 1 == sizeof(UB) ) ;
									_CHECK_STEP( 5 ) ;
	ub1 = -1 ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT( ub1 > 0 ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT( 2 == sizeof(H) ) ;
									_CHECK_STEP( 8 ) ;
	h1 = -1 ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT( h1 < 0 ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( 2 == sizeof(UH) ) ;
									_CHECK_STEP( 11 ) ;
	uh1 = -1 ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT( uh1 > 0 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT( 4 == sizeof(W) ) ;
									_CHECK_STEP( 14 ) ;
	w1 = -1 ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT( w1 < 0 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT( 4 == sizeof(UW) ) ;
									_CHECK_STEP( 17 ) ;
	uw1 = -1 ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT( uw1 > 0 ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( 1 == sizeof(VB) ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( 2 == sizeof(VH) ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( 4 == sizeof(VW) ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( sizeof(void *) == sizeof(VP) ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( sizeof(void (*)(void)) == sizeof(FP) ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( 2 <= sizeof(INT) ) ;
									_CHECK_STEP( 25 ) ;
	int1 = -1 ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT( int1 < 0 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT( 2 <= sizeof(UINT) ) ;
									_CHECK_STEP( 28 ) ;
	uint1 = -1 ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT( uint1 > 0 ) ;
									_CHECK_STEP( 30 ) ;
	bool1 = TRUE ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( bool1 == TRUE ) ;
									_CHECK_STEP( 32 ) ;
	bool1 = FALSE ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( bool1 == FALSE ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( 2 <= sizeof(FN) ) ;
									_CHECK_STEP( 35 ) ;
	fn1 = -1 ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( fn1 < 0 ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( 1 <= sizeof(ER) ) ;
									_CHECK_STEP( 38 ) ;
	er1 = -1 ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( er1 < 0 ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( 2 <= sizeof(ID) ) ;
									_CHECK_STEP( 41 ) ;
	id1 = -1 ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( id1 < 0 ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT( 1 <= sizeof(ATR) ) ;
									_CHECK_STEP( 44 ) ;
	atr1 = -1 ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( atr1 > 0 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT( 2 <= sizeof(STAT) ) ;
									_CHECK_STEP( 47 ) ;
	stat1 = -1 ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT( stat1 > 0 ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT( 1 <= sizeof(MODE) ) ;
									_CHECK_STEP( 50 ) ;
	mode1 = -1 ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT( mode1 > 0 ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT( 2 <= sizeof(PRI) ) ;
									_CHECK_STEP( 53 ) ;
	pri1 = -1 ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT( pri1 < 0 ) ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT( sizeof(SIZE) == sizeof(void *) ) ;
									_CHECK_STEP( 56 ) ;
	size1 = -1 ;
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT( size1 > 0 ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT( 2 <= sizeof(TMO) ) ;
									_CHECK_STEP( 59 ) ;
	tmo1 = -1 ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT( tmo1 < 0 ) ;
									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT( 2 <= sizeof(RELTIM) ) ;
									_CHECK_STEP( 62 ) ;
	reltim1 = -1 ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT( reltim1 > 0 ) ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT( 2 <= sizeof(SYSTIM) ) ;
									_CHECK_STEP( 65 ) ;
	systim1 = -1 ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( systim1 > 0 ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT( sizeof(VP_INT) >= sizeof(INT) && sizeof(VP_INT) >= sizeof(VP) ) ;
									_CHECK_STEP( 68 ) ;
	vp_int1 = (VP_INT) -1 ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT( (INT)vp_int1 < 0 ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT( 1 <= sizeof(ER_BOOL) ) ;
									_CHECK_STEP( 71 ) ;
	er_bool1 = TRUE ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT( er_bool1 == TRUE ) ;
									_CHECK_STEP( 73 ) ;
	er_bool1 = FALSE ;
									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT( er_bool1 == FALSE ) ;
									_CHECK_STEP( 75 ) ;
	er_bool1 = -1 ;
									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT( er_bool1 < 0 ) ;
									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT( 2 <= sizeof(ER_ID) ) ;
									_CHECK_STEP( 78 ) ;
	er_id1 = -1 ;
									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT( er_id1 < 0 ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT( 2 <= sizeof(ER_UINT) ) ;
									_CHECK_STEP( 81 ) ;
	er_uint1 = -1 ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT( er_uint1 < 0 ) ;
									_CHECK_STEP( 83 ) ;
	ext_tsk() ;
}
