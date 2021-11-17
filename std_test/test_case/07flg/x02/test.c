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
#define _LAST_STEP 105
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CFLG k_cflg1 = { TA_TFIFO, IFLGPTN_1 } ;
T_CFLG k_cflg2 = { TA_TPRI , IFLGPTN_0 } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 79 ) ;
	ercd = wai_flg( FLG_ID6, WAIPTN_0055, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 84 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 90 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 91 ) ;
	ercd = wai_flg( FLG_ID7, WAIPTN_0505, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 101 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 102 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0505 ) ;
									_CHECK_STEP( 103 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 40 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 54 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 56 ) ;
	ercd = wai_flg( FLG_ID4, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 68 ) ;
	ercd = wai_flg( FLG_ID5, WAIPTN_8000, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_8000 ) ;
									_CHECK_STEP( 76 ) ;
	ercd = wai_flg( FLG_ID6, WAIPTN_0055, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 85 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 86 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 87 ) ;
	ercd = wai_flg( FLG_ID7, WAIPTN_0005, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 94 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 95 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0005 ) ;
									_CHECK_STEP( 96 ) ;
	ercd = set_flg( FLG_ID7, SETPTN_0500 ) ;
									_CHECK_STEP( 97 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 98 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 34 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 37 ) ;
	ercd = wai_flg( FLG_ID1, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_0002 ) ;
									_CHECK_STEP( 47 ) ;
	ercd = wai_flg( FLG_ID2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ercd = wai_flg( FLG_ID3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_0002 ) ;
									_CHECK_STEP( 61 ) ;
	ercd = wai_flg( FLG_ID4, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 63 ) ;
	ercd = wai_flg( FLG_ID5, WAIPTN_8000, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_8000 ) ;
									_CHECK_STEP( 73 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_flg( ERR_FLG_ID, &k_cflg1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_cflg = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = cre_flg( E_FLG_ID1, pk_cflg ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = ERR_FLGATR ;
									_CHECK_STEP( 7 ) ;
	ercd = cre_flg( E_FLG_ID2, &k_cflg ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 9 ) ;
#ifdef ERR_IFLGPTN
	k_cflg = k_cflg1 ;
	k_cflg.iflgptn = ERR_IFLGPTN ;
									_CHECK_STEP( 10 ) ;
	ercd = cre_flg( E_FLG_ID3, &k_cflg ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 10 ) ;
									_CHECK_STEP( 11 ) ;
#endif
									_CHECK_STEP( 12 ) ;
	ercd = cre_flg( FLG_ID1, &k_cflg1 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	ercd = cre_flg( FLG_ID1, &k_cflg1 ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 16 ) ;
	ercd = cre_flg( FLG_ID2, &k_cflg2 ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WSGL ;
									_CHECK_STEP( 19 ) ;
	ercd = cre_flg( FLG_ID3, &k_cflg ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	k_cflg = k_cflg2 ;
	k_cflg.flgatr = TA_TPRI|TA_WSGL ;
									_CHECK_STEP( 22 ) ;
	ercd = cre_flg( FLG_ID4, &k_cflg ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WMUL ;
									_CHECK_STEP( 25 ) ;
	ercd = cre_flg( FLG_ID5, &k_cflg ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	k_cflg = k_cflg2 ;
	k_cflg.flgatr = TA_TPRI|TA_WMUL ;
									_CHECK_STEP( 28 ) ;
	ercd = cre_flg( FLG_ID6, &k_cflg ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WMUL|TA_CLR ;
									_CHECK_STEP( 31 ) ;
	ercd = cre_flg( FLG_ID7, &k_cflg ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	ercd = act_tsk( TASK_ID4 ) ;

									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	ercd = set_flg( FLG_ID1, SETPTN_0002 ) ;

									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = set_flg( FLG_ID2, SETPTN_0001 ) ;

									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ercd = set_flg( FLG_ID3, SETPTN_0002 ) ;

									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	ercd = set_flg( FLG_ID4, SETPTN_0001 ) ;

									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	ercd = set_flg( FLG_ID5, SETPTN_8000 ) ;

									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 81 ) ;
	ercd = set_flg( FLG_ID6, SETPTN_0001 ) ;

									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 89 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 92 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 93 ) ;
	ercd = set_flg( FLG_ID7, SETPTN_0005 ) ;

									_CHECK_STEP( 99 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 100 ) ;
	ercd = set_flg( FLG_ID7, SETPTN_0005 ) ;

									_CHECK_STEP( 104 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 105 ) ;
	ext_tsk() ;
}

