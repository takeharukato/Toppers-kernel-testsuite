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
#define _LAST_STEP 84
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB MBX1[TSZ_MPRIHD(MAXMPRI_3)] ;

T_CMBX k_cmbx1 = { TA_TFIFO|TA_MFIFO, 0, NULL } ;
T_CMBX k_cmbx2 = { TA_TPRI|TA_MFIFO, 0, NULL } ;
T_CMBX k_cmbx3 = { TA_TFIFO|TA_MPRI, MAXMPRI_3, NULL } ;
T_CMBX k_cmbx4 = { TA_TPRI|TA_MPRI, MAXMPRI_3, (VP)MBX1 } ;


void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 32 ) ;
	ercd = rcv_mbx( MBX_ID1, ppk_msg ) ;

									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT( pk_msg == &msg2 ) ;
									_CHECK_STEP( 42 ) ;
	ercd = rcv_mbx( MBX_ID2, ppk_msg ) ;

									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT( pk_msg == &msg21 ) ;
									_CHECK_STEP( 47 ) ;
	msg3.msgpri = MSGPRI_3 ;
									_CHECK_STEP( 48 ) ;
	ercd = snd_mbx( MBX_ID3, &msg3 ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 50 ) ;
	msg1.msgpri = MSGPRI_2 ;
									_CHECK_STEP( 51 ) ;
	ercd = snd_mbx( MBX_ID3, &msg1 ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	msg2.msgpri = MSGPRI_2 ;
									_CHECK_STEP( 54 ) ;
	ercd = snd_mbx( MBX_ID3, &msg2 ) ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 56 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 29 ) ;
	ercd = rcv_mbx( MBX_ID1, ppk_msg ) ;

									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( pk_msg == &msg1 ) ;
									_CHECK_STEP( 37 ) ;
	ercd = rcv_mbx( MBX_ID2, ppk_msg ) ;

									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT( pk_msg == &msg22 ) ;
									_CHECK_STEP( 61 ) ;
	ercd = rcv_mbx( MBX_ID3, ppk_msg ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT( pk_msg == &msg1 ) ;
									_CHECK_STEP( 64 ) ;
	ercd = rcv_mbx( MBX_ID3, ppk_msg ) ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( pk_msg == &msg2 ) ;
									_CHECK_STEP( 67 ) ;
	ercd = rcv_mbx( MBX_ID3, ppk_msg ) ;
									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT( pk_msg == &msg3 ) ;
									_CHECK_STEP( 70 ) ;
	msg22.msgpri = MSGPRI_2 ;
									_CHECK_STEP( 71 ) ;
	ercd = snd_mbx( MBX_ID4, &msg22 ) ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 73 ) ;
	msg21.msgpri = MSGPRI_1 ;
									_CHECK_STEP( 74 ) ;
	ercd = snd_mbx( MBX_ID4, &msg21 ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 76 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_mbx( ERR_MBX_ID, &k_cmbx1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_cmbx = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = cre_mbx( E_MBX_ID1, pk_cmbx ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	k_cmbx = k_cmbx1 ;
	k_cmbx.mbxatr = ERR_MBXATR ;
									_CHECK_STEP( 7 ) ;
	ercd = cre_mbx( E_MBX_ID2, &k_cmbx ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 9 ) ;
	k_cmbx = k_cmbx3 ;
	k_cmbx.maxmpri = ERR_MAXMPRI ;
									_CHECK_STEP( 10 ) ;
	ercd = cre_mbx( E_MBX_ID3, &k_cmbx ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 12 ) ;
	k_cmbx.maxmpri = 0 ;
									_CHECK_STEP( 13 ) ;
	ercd = cre_mbx( E_MBX_ID4, &k_cmbx ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 15 ) ;
#ifdef ERR_POINTER
	k_cmbx = k_cmbx3 ;
	k_cmbx.mprihd =  ERR_POINTER ;
									_CHECK_STEP( 16 ) ;
	ercd = cre_mbx( E_MBX_ID5, &k_cmbx ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 16 ) ;
									_CHECK_STEP( 17 ) ;
#endif
									_CHECK_STEP( 18 ) ;
	ercd = cre_mbx( MBX_ID1, &k_cmbx1 ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 20 ) ;
	ercd = cre_mbx( MBX_ID1, &k_cmbx1 ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 22 ) ;
	ercd = cre_mbx( MBX_ID2, &k_cmbx2 ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	ercd = cre_mbx( MBX_ID3, &k_cmbx3 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
	ercd = cre_mbx( MBX_ID4, &k_cmbx4 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = snd_mbx( MBX_ID1, &msg1 ) ;

									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ercd = snd_mbx( MBX_ID1, &msg2 ) ;

									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	ercd = snd_mbx( MBX_ID2, &msg21 ) ;

									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ercd = snd_mbx( MBX_ID2, &msg22 ) ;

									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	ercd = rcv_mbx( MBX_ID4, ppk_msg ) ;
									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT( pk_msg == &msg21 ) ;
									_CHECK_STEP( 81 ) ;
	ercd = rcv_mbx( MBX_ID4, ppk_msg ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	_CHECK_ASSERT( pk_msg == &msg22 ) ;
									_CHECK_STEP( 84 ) ;
	ext_tsk() ;
}

