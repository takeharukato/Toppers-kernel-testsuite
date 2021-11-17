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
#include "test_x03.h"
#include "kernel_id.h"

#define _TEST_TIME 3
#define _LAST_STEP 103
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CFLG k_cflg1 = { TA_TFIFO, IFLGPTN_1 } ;
T_CFLG k_cflg2 = { TA_TPRI , IFLGPTN_0 } ;

ER_ID flgid1,flgid2,flgid3,flgid4,flgid5,flgid6,flgid7;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 75 ) ;
	ercd = wai_flg( flgid6, WAIPTN_0055, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 80 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 86 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 87 ) ;
	ercd = wai_flg( flgid7, WAIPTN_0505, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 97 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 98 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0505 ) ;
									_CHECK_STEP( 99 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 36 ) ;
	ercd = wai_flg( flgid1, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = wai_flg( flgid2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 50 ) ;
	ercd = wai_flg( flgid3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ercd = wai_flg( flgid4, WAIPTN_0001, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 64 ) ;
	ercd = wai_flg( flgid5, WAIPTN_8000, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_8000 ) ;
									_CHECK_STEP( 72 ) ;
	ercd = wai_flg( flgid6, WAIPTN_0055, TWF_ORW, p_flgptn ) ;

									_CHECK_STEP( 81 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 83 ) ;
	ercd = wai_flg( flgid7, WAIPTN_0005, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 90 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 91 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0005 ) ;
									_CHECK_STEP( 92 ) ;
	ercd = set_flg( flgid7, SETPTN_0500 ) ;
									_CHECK_STEP( 93 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 94 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 30 ) ;
	ercd = wai_flg( flgid1, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001 ) ;
									_CHECK_STEP( 33 ) ;
	ercd = wai_flg( flgid1, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_0002 ) ;
									_CHECK_STEP( 43 ) ;
	ercd = wai_flg( flgid2, WAIPTN_0001, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 45 ) ;
	ercd = wai_flg( flgid3, WAIPTN_0002, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_0002 ) ;
									_CHECK_STEP( 57 ) ;
	ercd = wai_flg( flgid4, WAIPTN_0002, TWF_ORW, p_flgptn ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ercd = wai_flg( flgid5, WAIPTN_8000, TWF_ANDW, p_flgptn ) ;

									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT( flgptn == SETPTN_0001|SETPTN_8000 ) ;
									_CHECK_STEP( 69 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	UINT  flgid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cflg = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_flg( pk_cflg ) ;
	if ( ercd > 0 ) flgid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = ERR_FLGATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_flg( &k_cflg ) ;
	if ( ercd > 0 ) flgid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_IFLGPTN
	k_cflg = k_cflg1 ;
	k_cflg.iflgptn = ERR_IFLGPTN ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_flg( &k_cflg ) ;
	if ( ercd > 0 ) flgid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
	flgid1 = acre_flg( &k_cflg1 ) ;
	if ( flgid1 > 0 ) flgid_cnt++;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( flgid1 > 0 ) ;
_PRINT_VER( flgid1 ) ;
									_CHECK_STEP( 12 ) ;
	flgid2 = acre_flg( &k_cflg2 ) ;
	if ( flgid2 > 0 ) flgid_cnt++;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT( flgid2 > 0 ) ;
_PRINT_VER( flgid2 ) ;
									_CHECK_STEP( 14 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WSGL ;
									_CHECK_STEP( 15 ) ;
	flgid3 = acre_flg( &k_cflg ) ;
	if ( flgid3 > 0 ) flgid_cnt++;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT( flgid3 > 0 ) ;
_PRINT_VER( flgid3 ) ;
									_CHECK_STEP( 17 ) ;
	k_cflg = k_cflg2 ;
	k_cflg.flgatr = TA_TPRI|TA_WSGL ;
									_CHECK_STEP( 18 ) ;
	flgid4 = acre_flg( &k_cflg ) ;
	if ( flgid4 > 0 ) flgid_cnt++;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( flgid4 > 0 ) ;
_PRINT_VER( flgid4 ) ;
									_CHECK_STEP( 20 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WMUL ;
									_CHECK_STEP( 21 ) ;
	flgid5 = acre_flg( &k_cflg ) ;
	if ( flgid5 > 0 ) flgid_cnt++;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( flgid5 > 0 ) ;
_PRINT_VER( flgid5 ) ;
									_CHECK_STEP( 23 ) ;
	k_cflg = k_cflg2 ;
	k_cflg.flgatr = TA_TPRI|TA_WMUL ;
									_CHECK_STEP( 24 ) ;
	flgid6 = acre_flg( &k_cflg ) ;
	if ( flgid6 > 0 ) flgid_cnt++;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT( flgid6 > 0 ) ;
_PRINT_VER( flgid6 ) ;
									_CHECK_STEP( 26 ) ;
	k_cflg = k_cflg1 ;
	k_cflg.flgatr = TA_TFIFO|TA_WMUL|TA_CLR ;
									_CHECK_STEP( 27 ) ;
	flgid7 = acre_flg( &k_cflg ) ;
	if ( flgid7 > 0 ) flgid_cnt++;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( flgid7 > 0 ) ;
_PRINT_VER( flgid7 ) ;
									_CHECK_STEP( 29 ) ;
	ercd = act_tsk( TASK_ID4 ) ;

									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = set_flg( flgid1, SETPTN_0002 ) ;

									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = set_flg( flgid2, SETPTN_0001 ) ;

									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	ercd = set_flg( flgid3, SETPTN_0002 ) ;

									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ercd = set_flg( flgid4, SETPTN_0001 ) ;

									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	ercd = set_flg( flgid5, SETPTN_8000 ) ;

									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 74 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 77 ) ;
	ercd = set_flg( flgid6, SETPTN_0001 ) ;

									_CHECK_STEP( 84 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 85 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 89 ) ;
	ercd = set_flg( flgid7, SETPTN_0005 ) ;

									_CHECK_STEP( 95 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 96 ) ;
	ercd = set_flg( flgid7, SETPTN_0005 ) ;

									_CHECK_STEP( 100 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 101 ) ;
	while ( flgid_cnt <= ACRE_CNT ) {
		ercd = acre_flg( &k_cflg1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) flgid_cnt++;
		else break;
		}
									_CHECK_STEP( 102 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 103 ) ;
	ext_tsk() ;
}

