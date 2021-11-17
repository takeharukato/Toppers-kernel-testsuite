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
#include "test.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 93
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB DTQ1[TSZ_DTQ(DTQCNT_2)] ;

T_CDTQ k_cdtq1 = { TA_TFIFO, DTQCNT_1, NULL } ;
T_CDTQ k_cdtq2 = { TA_TPRI , DTQCNT_1, NULL } ;
T_CDTQ k_cdtq3 = { TA_TPRI , DTQCNT_2, (VP)DTQ1 } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 33 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( data == MEMORY ) ;
									_CHECK_STEP( 43 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_22 ) ;

									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 64 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_DD ) ;

									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	ercd = snd_dtq( DTQ_ID3, DATA_11 ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 71 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 30 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( data == DATA_33 ) ;
									_CHECK_STEP( 38 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_33 ) ;

									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_EE ) ;

									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 76 ) ;
	ercd = snd_dtq( DTQ_ID3, DATA_22 ) ;
									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_dtq( ERR_DTQ_ID, &k_cdtq1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_cflg = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = cre_dtq( E_FLG_ID1, pk_cdtq ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqatr = ERR_DTQATR ;
									_CHECK_STEP( 7 ) ;
	ercd = cre_dtq( E_DTQ_ID2, &k_cdtq ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 9 ) ;
#ifdef ERR_DTQCNT
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqcnt = ERR_DTQCNT ;
									_CHECK_STEP( 10 ) ;
	ercd = cre_dtq( E_DTQ_ID3, &k_cdtq ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 10 ) ;
									_CHECK_STEP( 11 ) ;
#endif
									_CHECK_STEP( 12 ) ;
#ifdef ERR_POINTER
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtq = ERR_POINTER ;
									_CHECK_STEP( 13 ) ;
	ercd = cre_dtq( E_DTQ_ID4, &k_cdtq ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 13 ) ;
									_CHECK_STEP( 14 ) ;
#endif
									_CHECK_STEP( 15 ) ;
	ercd = cre_dtq( DTQ_ID1, &k_cdtq1 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = cre_dtq( DTQ_ID1, &k_cdtq1 ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 19 ) ;
	ercd = cre_dtq( DTQ_ID2, &k_cdtq2 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = cre_dtq( DTQ_ID3, &k_cdtq3 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_55 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 25 ) ;
	p_data = &data ;
									_CHECK_STEP( 26 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT( data == DATA_55 ) ;
									_CHECK_STEP( 29 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_33 ) ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = snd_dtq( DTQ_ID1, MEMORY ) ;

									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 45 ) ;
	ercd = snd_dtq( DTQ_ID1, DATA_00 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = wup_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ercd = snd_dtq( DTQ_ID2, DATA_FF ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT( data == DATA_00 ) ;
									_CHECK_STEP( 62 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;

									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( data == DATA_33 ) ;
									_CHECK_STEP( 67 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;

									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT( data == DATA_FF ) ;
									_CHECK_STEP( 74 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;

									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT( data == DATA_DD ) ;
									_CHECK_STEP( 81 ) ;
	ercd = rcv_dtq( DTQ_ID2, p_data ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	_CHECK_ASSERT( data == DATA_EE ) ;
									_CHECK_STEP( 84 ) ;
	ercd = rcv_dtq( DTQ_ID3, p_data ) ;
									_CHECK_STEP( 85 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 86 ) ;
	_CHECK_ASSERT( data == DATA_11 ) ;
									_CHECK_STEP( 87 ) ;
	ercd = rcv_dtq( DTQ_ID3, p_data ) ;
									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 89 ) ;
	_CHECK_ASSERT( data == DATA_22 ) ;
									_CHECK_STEP( 90 ) ;
	k_cdtq = k_cdtq1 ;
	k_cdtq.dtqcnt = DTQCNT_MAX ;
_PRINT_VER( TSZ_DTQ( DTQCNT_MAX ) ) ;
									_CHECK_STEP( 91 ) ;
	ercd = cre_dtq( E_DTQ_ID5, &k_cdtq ) ;
									_CHECK_STEP( 92 ) ;
	_CHECK_ASSERT_E_NOMEM( ercd ) ;
									_CHECK_STEP( 93 ) ;
	ext_tsk() ;
}

