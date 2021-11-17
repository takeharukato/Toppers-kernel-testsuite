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
#define _LAST_STEP 91
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB DTQ1[TSZ_DTQ(DTQCNT_2)] ;

T_CDTQ k_cdtq1 = { TA_TFIFO, DTQCNT_1, NULL } ;
T_CDTQ k_cdtq2 = { TA_TPRI , DTQCNT_1, NULL } ;
T_CDTQ k_cdtq3 = { TA_TPRI , DTQCNT_2, (VP)DTQ1 } ;

ER_ID dtqid1, dtqid2, dtqid3;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 29 ) ;
	ercd = rcv_dtq( dtqid1, p_data ) ;

									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT( data == MEMORY ) ;
									_CHECK_STEP( 39 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ercd = snd_dtq( dtqid1, DATA_22 ) ;

									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 60 ) ;
	ercd = snd_dtq( dtqid2, DATA_DD ) ;

									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	ercd = snd_dtq( dtqid3, DATA_11 ) ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 67 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 26 ) ;
	ercd = rcv_dtq( dtqid1, p_data ) ;

									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( data == DATA_33 ) ;
									_CHECK_STEP( 34 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 45 ) ;
	ercd = snd_dtq( dtqid1, DATA_33 ) ;

									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = snd_dtq( dtqid2, DATA_EE ) ;

									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 72 ) ;
	ercd = snd_dtq( dtqid3, DATA_22 ) ;
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 74 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	UINT  dtqid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cflg = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_dtq( pk_cdtq ) ;
	if ( ercd > 0 ) dtqid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqatr = ERR_DTQATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_dtq( &k_cdtq ) ;
	if ( ercd > 0 ) dtqid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
#ifdef ERR_DTQCNT
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqcnt = ERR_DTQCNT ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_dtq( &k_cdtq ) ;
	if ( ercd > 0 ) dtqid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 8 ) ;
									_CHECK_STEP( 9 ) ;
#endif
									_CHECK_STEP( 10 ) ;
#ifdef ERR_POINTER
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtq = ERR_POINTER ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_dtq( &k_cdtq ) ;
	if ( ercd > 0 ) dtqid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 11 ) ;
									_CHECK_STEP( 12 ) ;
#endif
									_CHECK_STEP( 13 ) ;
	dtqid1 = acre_dtq( &k_cdtq1 ) ;
	if ( dtqid1 > 0 ) dtqid_cnt++;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT( dtqid1 > 0 ) ;
_PRINT_VER( dtqid1 ) ;
									_CHECK_STEP( 15 ) ;
	dtqid2 = acre_dtq( &k_cdtq2 ) ;
	if ( dtqid2 > 0 ) dtqid_cnt++;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT( dtqid2 > 0 ) ;
_PRINT_VER( dtqid2 ) ;
									_CHECK_STEP( 17 ) ;
	dtqid3 = acre_dtq( &k_cdtq3 ) ;
	if ( dtqid3 > 0 ) dtqid_cnt++;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT( dtqid3 > 0 ) ;
_PRINT_VER( dtqid3 ) ;
									_CHECK_STEP( 19 ) ;
	ercd = snd_dtq( dtqid1, DATA_55 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	p_data = &data ;
									_CHECK_STEP( 22 ) ;
	ercd = rcv_dtq( dtqid1, p_data ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( data == DATA_55 ) ;
									_CHECK_STEP( 25 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = snd_dtq( dtqid1, DATA_33 ) ;

									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = snd_dtq( dtqid1, MEMORY ) ;

									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 41 ) ;
	ercd = snd_dtq( dtqid1, DATA_00 ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
	ercd = wup_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = snd_dtq( dtqid2, DATA_FF ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = rcv_dtq( dtqid1, p_data ) ;

									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT( data == DATA_00 ) ;
									_CHECK_STEP( 58 ) ;
	ercd = rcv_dtq( dtqid1, p_data ) ;

									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT( data == DATA_33 ) ;
									_CHECK_STEP( 63 ) ;
	ercd = rcv_dtq( dtqid2, p_data ) ;

									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT( data == DATA_FF ) ;
									_CHECK_STEP( 70 ) ;
	ercd = rcv_dtq( dtqid2, p_data ) ;

									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT( data == DATA_DD ) ;
									_CHECK_STEP( 77 ) ;
	ercd = rcv_dtq( dtqid2, p_data ) ;
									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT( data == DATA_EE ) ;
									_CHECK_STEP( 80 ) ;
	ercd = rcv_dtq( dtqid3, p_data ) ;
									_CHECK_STEP( 81 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT( data == DATA_11 ) ;
									_CHECK_STEP( 83 ) ;
	ercd = rcv_dtq( dtqid3, p_data ) ;
									_CHECK_STEP( 84 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 85 ) ;
	_CHECK_ASSERT( data == DATA_22 ) ;
									_CHECK_STEP( 86 ) ;
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqcnt = DTQCNT_MAX ;
_PRINT_VER( TSZ_DTQ( DTQCNT_MAX ) ) ;
									_CHECK_STEP( 87 ) ;
	ercd = acre_dtq( &k_cdtq ) ;
	if ( ercd > 0 ) dtqid_cnt++;
									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_NOMEM( ercd ) ;
									_CHECK_STEP( 89 ) ;
	while ( dtqid_cnt <= ACRE_CNT ) {
		ercd = acre_dtq( &k_cdtq1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) dtqid_cnt++;
		else break;
		}
									_CHECK_STEP( 90 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 91 ) ;
	ext_tsk() ;
}

