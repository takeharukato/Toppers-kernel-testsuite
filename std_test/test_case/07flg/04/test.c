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

#define _TEST_TIME 3
#define _LAST_STEP 54
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = twai_flg( ERR_FLG_ID, WAIPTN_0001, TWF_ANDW, p_flgptn, TMO_POL ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_WAIPTN
	ercd = twai_flg( FLG_ID1, ERR_WAIPTN, TWF_ORW, p_flgptn, TMO_POL ) ;
#endif
									_CHECK_STEP( 4 ) ;
#ifdef ERR_WAIPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 5 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0001, ERR_WFMODE, p_flgptn, TMO_POL ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_POINTER
	ercd = twai_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, ERR_POINTER, TMO_POL ) ;
#endif
									_CHECK_STEP( 8 ) ;
#ifdef ERR_POINTER
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 9 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, p_flgptn, ERR_TMO ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 11 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0000, TWF_ORW, p_flgptn, TMO_POL ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_0055 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0001, TWF_ORW, p_flgptn, TMO_POL ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0055 ) ;
									_CHECK_STEP( 18 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0002, TWF_ANDW, p_flgptn, TMO_POL ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 20 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0020, TWF_ORW, p_flgptn, TMO_1 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_5500, TWF_ANDW, p_flgptn, TMO_100 ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_5555 ) ;
									_CHECK_STEP( 30 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0002, TWF_ANDW, p_flgptn, TMO_FEVR ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = twai_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn, TMO_FEVR ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_5555 ) ;
									_CHECK_STEP( 41 ) ;
	ercd = pol_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 43 ) ;
	ercd = set_flg( FLG_ID2, SETPTN_8000 ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 45 ) ;
	ercd = twai_flg( FLG_ID2, WAIPTN_8000, TWF_ANDW, p_flgptn, TMO_FEVR ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_8000 ) ;
									_CHECK_STEP( 48 ) ;
	ercd = pol_flg( FLG_ID2, WAIPTN_8000, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ercd = twai_flg( FLG_ID2, WAIPTN_0001, TWF_ANDW, p_flgptn, TMO_POL ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;

dis_dsp() ;
									_CHECK_STEP( 21 ) ;
ena_dsp() ;
	ercd = dly_tsk( DLYTIM_5 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 25 ) ;
	ercd = twai_flg( FLG_ID1, WAIPTN_0055, TWF_ORW, p_flgptn, TMO_100 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_5500 ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd = dly_tsk( DLYTIM_1000 ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = rel_wai( TASK_ID1 ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = set_flg( FLG_ID2, SETPTN_5555 ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	ext_tsk() ;
}

