/* TOPPERSカーネルテストスイート
 * 
 *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
 * 
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 *
 *  @(#) $Id: test.c,v 1.0 2004/04/22 00:00:00 morita Exp $
 */

#include <kernel.h>
#include "test_x02.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 82
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB MBX1[TSZ_MPRIHD(MAXMPRI_3)] ;

T_CMBX k_cmbx1 = { TA_TFIFO|TA_MFIFO, 0, NULL } ;
T_CMBX k_cmbx2 = { TA_TPRI|TA_MFIFO, 0, NULL } ;
T_CMBX k_cmbx3 = { TA_TFIFO|TA_MPRI, MAXMPRI_3, NULL } ;
T_CMBX k_cmbx4 = { TA_TPRI|TA_MPRI, MAXMPRI_3, (VP)MBX1 } ;

ER_ID  mbx_id1, mbx_id2, mbx_id3, mbx_id4;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 28 ) ;
	ercd = rcv_mbx( mbx_id1, ppk_msg ) ;

									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( pk_msg == &msg2 ) ;
									_CHECK_STEP( 38 ) ;
	ercd = rcv_mbx( mbx_id2, ppk_msg ) ;

									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( pk_msg == &msg21 ) ;
									_CHECK_STEP( 43 ) ;
	msg3.msgpri = MSGPRI_3 ;
									_CHECK_STEP( 44 ) ;
	ercd = snd_mbx( mbx_id3, &msg3 ) ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
	msg1.msgpri = MSGPRI_2 ;
									_CHECK_STEP( 47 ) ;
	ercd = snd_mbx( mbx_id3, &msg1 ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	msg2.msgpri = MSGPRI_2 ;
									_CHECK_STEP( 50 ) ;
	ercd = snd_mbx( mbx_id3, &msg2 ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 25 ) ;
	ercd = rcv_mbx( mbx_id1, ppk_msg ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT( pk_msg == &msg1 ) ;
									_CHECK_STEP( 33 ) ;
	ercd = rcv_mbx( mbx_id2, ppk_msg ) ;

									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT( pk_msg == &msg22 ) ;
									_CHECK_STEP( 57 ) ;
	ercd = rcv_mbx( mbx_id3, ppk_msg ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT( pk_msg == &msg1 ) ;
									_CHECK_STEP( 60 ) ;
	ercd = rcv_mbx( mbx_id3, ppk_msg ) ;
									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT( pk_msg == &msg2 ) ;
									_CHECK_STEP( 63 ) ;
	ercd = rcv_mbx( mbx_id3, ppk_msg ) ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT( pk_msg == &msg3 ) ;
									_CHECK_STEP( 66 ) ;
	msg22.msgpri = MSGPRI_2 ;
									_CHECK_STEP( 67 ) ;
	ercd = snd_mbx( mbx_id4, &msg22 ) ;
									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	msg21.msgpri = MSGPRI_1 ;
									_CHECK_STEP( 70 ) ;
	ercd = snd_mbx( mbx_id4, &msg21 ) ;
									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 72 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	UINT  mbxid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cmbx = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_mbx( pk_cmbx ) ;
	if ( ercd > 0 ) mbxid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cmbx = k_cmbx1 ;
	k_cmbx.mbxatr = ERR_MBXATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_mbx( &k_cmbx ) ;
	if ( ercd > 0 ) mbxid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
	k_cmbx = k_cmbx3 ;
	k_cmbx.maxmpri = ERR_MAXMPRI ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_mbx( &k_cmbx ) ;
	if ( ercd > 0 ) mbxid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 10 ) ;
	k_cmbx.maxmpri = 0 ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_mbx( &k_cmbx ) ;
	if ( ercd > 0 ) mbxid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;
#ifdef ERR_POINTER
	k_cmbx = k_cmbx3 ;
	k_cmbx.mprihd =  ERR_POINTER ;
									_CHECK_STEP( 14 ) ;
	ercd = acre_mbx( &k_cmbx ) ;
	if ( ercd > 0 ) mbxid_cnt++;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 14 ) ;
									_CHECK_STEP( 15 ) ;
#endif
									_CHECK_STEP( 16 ) ;
	mbx_id1 = acre_mbx( &k_cmbx1 ) ;
	if ( mbx_id1 > 0 ) mbxid_cnt++;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT( mbx_id1 > 0 ) ;
_PRINT_VER( mbx_id1 ) ;
									_CHECK_STEP( 18 ) ;
	mbx_id2 = acre_mbx( &k_cmbx2 ) ;
	if ( mbx_id2 > 0 ) mbxid_cnt++;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( mbx_id2 > 0 ) ;
_PRINT_VER( mbx_id2 ) ;
									_CHECK_STEP( 20 ) ;	
	mbx_id3 = acre_mbx( &k_cmbx3 ) ;
	if ( mbx_id3 > 0 ) mbxid_cnt++;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( mbx_id3 > 0 ) ;
_PRINT_VER( mbx_id3 ) ;
									_CHECK_STEP( 22 ) ;
	mbx_id4 = acre_mbx( &k_cmbx4 ) ;
	if ( mbx_id4 > 0 ) mbxid_cnt++;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( mbx_id4 > 0 ) ;
_PRINT_VER( mbx_id4 ) ;
									_CHECK_STEP( 24 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	ercd = snd_mbx( mbx_id1, &msg1 ) ;

									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = snd_mbx( mbx_id1, &msg2 ) ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = snd_mbx( mbx_id2, &msg21 ) ;

									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	ercd = snd_mbx( mbx_id2, &msg22 ) ;

									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 74 ) ;
	ercd = rcv_mbx( mbx_id4, ppk_msg ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT( pk_msg == &msg21 ) ;
									_CHECK_STEP( 77 ) ;
	ercd = rcv_mbx( mbx_id4, ppk_msg ) ;
									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT( pk_msg == &msg22 ) ;
									_CHECK_STEP( 80 ) ;
	while ( mbxid_cnt <= ACRE_CNT ) {
		ercd = acre_mbx( &k_cmbx1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) mbxid_cnt++;
		else break;
		}
									_CHECK_STEP( 81 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 82 ) ;
	ext_tsk() ;
}

