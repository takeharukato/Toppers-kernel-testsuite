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
#define _LAST_STEP 76
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CTSK k_ctsk3 = { TA_HLNG|TA_ACT, EXINF_3, TASK3,  ITSKPRI_3, STKSZ, NULL };
T_DTEX k_dtex1 = { TA_HLNG, TEXRTN_1 } ;
T_DTEX k_dtex2 = { TA_HLNG, TEXRTN_2 } ;
T_DTEX e_dtex1 = { TA_HLNG, NULL } ;


void TASK1(VP_INT exinf)
{
	ER ercd ;

									_CHECK_STEP( 19 ) ;
	ercd = dis_dsp() ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = ena_tex() ;

									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	state = sns_tex() ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 51 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 62 ) ;
	ercd = def_tex( TSK_SELF, NULL ) ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 64 ) ;
	ercd = dis_tex() ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 66 ) ;
	ext_tsk() ;
}

void TEXRTN_1(TEXPTN texptn, VP_INT exinf)
{
	ER ercd ;
	static nCount = 0 ;
	nCount++ ;
	if ( nCount == 1 ) {
									_CHECK_STEP( 22 ) ;
		_CHECK_ASSERT( texptn == RASPTN_1111 ) ;
									_CHECK_STEP( 23 ) ;
		_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 24 ) ;
		ercd = ena_dsp() ;
									_CHECK_STEP( 25 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
		state = sns_ctx() ;
									_CHECK_STEP( 27 ) ;
		_CHECK_ASSERT( state == FALSE ) ;
									_CHECK_STEP( 28 ) ;
		ercd = ref_tex( TASK_ID1, &k_rtex ) ;
									_CHECK_STEP( 29 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
		_CHECK_ASSERT( k_rtex.texstat == TTEX_DIS ) ;
									_CHECK_STEP( 31 ) ;
		_CHECK_ASSERT( k_rtex.pndptn == 0 ) ;
									_CHECK_STEP( 32 ) ;
		ercd = slp_tsk() ;

									_CHECK_STEP( 43 ) ;
		_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
		return ;
	}
	else if ( nCount == 2 ) {
									_CHECK_STEP( 45 ) ;
		_CHECK_ASSERT( texptn == RASPTN_AAAE ) ;
									_CHECK_STEP( 46 ) ;
		_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 47 ) ;
		return ;
	}
	else {
	}
}

void TEXRTN_2(TEXPTN texptn, VP_INT exinf)
{
									_CHECK_STEP( 58 ) ;
		_CHECK_ASSERT( texptn == RASPTN_1 ) ;
									_CHECK_STEP( 59 ) ;
		_CHECK_ASSERT( exinf == EXINF_1 ) ;
									_CHECK_STEP( 60 ) ;
		return ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = def_tex( ERR_TASK_ID, &k_dtex1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = def_tex( TASK_ID3, &k_dtex1 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 5 ) ;
#ifdef ERR_POINTER
	pk_dtex = ERR_POINTER ;
									_CHECK_STEP( 6 ) ;
	ercd = def_tex( E_TASK_ID1, pk_dtex ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 6 ) ;
									_CHECK_STEP( 7 ) ;
#endif
									_CHECK_STEP( 8 ) ;
	k_dtex = e_dtex1;
	k_dtex.texatr = ERR_TEXATR;
									_CHECK_STEP( 9 ) ;
	ercd = def_tex( E_TASK_ID1, &k_dtex ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 11 ) ;
#ifdef ERR_POINTER
	k_dtex = e_dtex1;
	k_dtex.texrtn = ERR_POINTER;
									_CHECK_STEP( 12 ) ;
	ercd = def_tex( E_TASK_ID1, &k_dtex ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 12 ) ;
									_CHECK_STEP( 13 ) ;
#endif
									_CHECK_STEP( 14 ) ;
	ercd = def_tex( TASK_ID1, &k_dtex1 ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 16 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_1111 ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ercd = chg_pri( TASK_ID1, ITSKPRI_1 ) ;

									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_AAAA ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_4 ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = ref_tex( TASK_ID1, &k_rtex ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( k_rtex.texstat == TTEX_DIS ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT( k_rtex.pndptn == RASPTN_AAAE ) ;
									_CHECK_STEP( 42 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_1 ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = def_tex( TASK_ID1, &k_dtex2 ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 68 ) ;
	ercd = def_tex( TASK_ID1, &k_dtex1 ) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	ercd = ras_tex( TASK_ID1, RASPTN_1111 ) ;
									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 72 ) ;
	ercd = cre_tsk( TASK_ID3, &k_ctsk3 ) ;
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 74 ) ;
	ercd = ref_tex( TASK_ID3, &k_rtex ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 76 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ext_tsk() ;
}

