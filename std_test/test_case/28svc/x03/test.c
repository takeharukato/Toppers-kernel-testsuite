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
#define _LAST_STEP 13
#define _NEED_TEST_ROUTINES
#include "test_com.h"
#include "hw_routines.h"

T_DSVC k_dsvc1 = { TA_HLNG    , SVCRTN_1   } ;
T_DSVC k_dsvc2 = { TA_HLNG    , SVCRTN_2   } ;
T_DSVC e_dsvc1 = { TA_HLNG    , NULL   } ;

void TASK1(VP_INT exinf)
{
	ER ercd;
									_CHECK_STEP( 1 ) ;
	ercd = cal_svc(FNCD_2 , NULL, NULL, NULL, NULL, NULL) ;
	_CHECK_ASSERT_E_RSFN( ercd ) ;
									_CHECK_STEP( 2 ) ;
	ercd = cal_svc( FNCD_1, (VP_INT)"Hello", (VP_INT)5, NULL, NULL, NULL) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT( ercd == SVC_RDATA_22 ) ;
									_CHECK_STEP( 8 ) ;
	ercd = def_svc( FNCD_2, &k_dsvc2 ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	ercd = cal_svc( FNCD_2, (VP_INT)"Hello", (VP_INT)5, NULL, NULL, NULL) ;
									_CHECK_STEP( 12 ) ;
	_PRINT_VER( ercd ) ;
									_CHECK_STEP( 13 ) ;
	ext_tsk() ;
}

ER_UINT SVCRTN_1(VP_INT arg1, VP_INT arg2, VP_INT arg3, VP_INT arg4, VP_INT arg5)
{
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT( !strcmp((char *)arg1, "Hello") ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT( (INT)arg2 == 5 ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT( arg3 == NULL ) ;
									_CHECK_STEP( 6 ) ;
	return SVC_RDATA_22;
}

BOOL SVCRTN_2(VP_INT arg1, VP_INT arg2, VP_INT arg3, VP_INT arg4, VP_INT arg5)
{
									_CHECK_STEP( 11 ) ;
	return (arg1 != NULL) ;
}

