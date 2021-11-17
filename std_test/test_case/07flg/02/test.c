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
#define _LAST_STEP 97
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 53 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_1111 ) ;
									_CHECK_STEP( 66 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0000, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 68 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_AAAA, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_AAAA ) ;
									_CHECK_STEP( 71 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 74 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_0002 ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 76 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0002 ) ;
									_CHECK_STEP( 79 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 81 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_8000, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 84 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 85 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_8000 ) ;
									_CHECK_STEP( 86 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_8000, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 87 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 88 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_5555 ) ;
									_CHECK_STEP( 89 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 90 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_5555, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 91 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 92 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_5555 ) ;
									_CHECK_STEP( 93 ) ;
	ercd = pol_flg( FLG_ID3, WAIPTN_5555, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 94 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 95 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = set_flg( ERR_FLG_ID, SETPTN_1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_SETPTN
	ercd = set_flg( FLG_ID1, ERR_SETPTN ) ;
#endif
									_CHECK_STEP( 4 ) ;
#ifdef ERR_SETPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 5 ) ;
	ercd = clr_flg( ERR_FLG_ID, SETPTN_1 ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_CLRPTN
	ercd = clr_flg( FLG_ID1, ERR_CLRPTN ) ;
#endif
									_CHECK_STEP( 8 ) ;
#ifdef ERR_CLRPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 9 ) ;
	ercd = wai_flg( ERR_FLG_ID, WAIPTN_1, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 11 ) ;
#ifdef ERR_WAIPTN
	ercd = wai_flg( FLG_ID1, ERR_WAIPTN, TWF_ORW, p_flgptn ) ;
#endif
									_CHECK_STEP( 12 ) ;
#ifdef ERR_WAIPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 13 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_1, ERR_WFMODE, p_flgptn ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 15 ) ;
#ifdef ERR_POINTER
	ercd = wai_flg( FLG_ID1, WAIPTN_1, TWF_ANDW, ERR_POINTER ) ;
#endif
									_CHECK_STEP( 16 ) ;
#ifdef ERR_POINTER
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 17 ) ;
	ercd = pol_flg( ERR_FLG_ID, WAIPTN_1, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 19 ) ;
#ifdef ERR_WAIPTN
	ercd = pol_flg( FLG_ID1, ERR_WAIPTN, TWF_ORW, p_flgptn ) ;
#endif
									_CHECK_STEP( 20 ) ;
#ifdef ERR_WAIPTN
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 21 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_1, ERR_WFMODE, p_flgptn ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 23 ) ;
#ifdef ERR_POINTER
	ercd = pol_flg( FLG_ID1, WAIPTN_1, TWF_ANDW, ERR_POINTER ) ;
#endif
									_CHECK_STEP( 24 ) ;
#ifdef ERR_POINTER
	_CHECK_ASSERT_E_PAR( ercd ) ;
#endif
									_CHECK_STEP( 25 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_5555 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = set_flg( FLG_ID2, SETPTN_AAAA ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_AAAA ) ;
									_CHECK_STEP( 32 ) ;
	ercd = pol_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = clr_flg( FLG_ID1, CLRPTN_0000 ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0000, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_0055 ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0050, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0055 ) ;
									_CHECK_STEP( 45 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_5500 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = pol_flg( FLG_ID1, WAIPTN_0055, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_5555 ) ;
									_CHECK_STEP( 50 ) ;
	ercd = clr_flg( FLG_ID1, CLRPTN_0000 ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ercd = rel_wai( TASK_ID1 ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_1111 ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_8000 ) ;
									_CHECK_STEP( 96 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 97 ) ;
	ext_tsk() ;
}

