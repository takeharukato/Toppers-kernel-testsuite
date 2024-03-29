/* TOPPERSカーネルテストスイート
 * 
 *  Copyright (C) 2003-2004 by Advanced Data Controls, Corp
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation
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

#define _TEST_TIME 4
#define _LAST_STEP 84
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 33 ) ;
	ercd = tsnd_dtq( DTQ_ID1, DATA_44, TMO_FEVR ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ercd = slp_tsk() ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 64 ) ;
	ercd = tsnd_dtq( DTQ_ID2, DATA_99, TMO_100 ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 68 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 30 ) ;
	ercd = tsnd_dtq( DTQ_ID1, DATA_33, TMO_200 ) ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 46 ) ;
	ercd = slp_tsk() ;
									_CHECK_STEP( 59 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 60 ) ;
	ercd = tsnd_dtq( DTQ_ID2, DATA_88, TMO_100 ) ;
									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 78 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 6 ) ;
	ercd = rcv_dtq( DTQ_ID1, p_data ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( data == DATA_11 ) ;
									_CHECK_STEP( 11 ) ;
	ercd = tsnd_dtq( DTQ_ID1, MEMORY, TMO_100 ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 13 ) ;
	ercd = tsnd_dtq( DTQ_ID1, DATA_77, TMO_200 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = slp_tsk() ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = tsnd_dtq( DTQ_ID1, DATA_22, TMO_100 ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 41 ) ;
	ercd = slp_tsk() ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 56 ) ;
	ercd = tsnd_dtq( DTQ_ID2, DATA_77, TMO_FEVR ) ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 73 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = tsnd_dtq( ERR_DTQ_ID, DATA_55, TMO_10 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = tsnd_dtq( DTQ_ID1, DATA_55, ERR_TMO ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 5 ) ;
	ercd = act_tsk( TASK_ID3 ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = tsnd_dtq( DTQ_ID1, DATA_11, TMO_POL ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = prcv_dtq( DTQ_ID1, p_data ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( data == MEMORY ) ;
									_CHECK_STEP( 20 ) ;
	ercd = prcv_dtq( DTQ_ID1, p_data ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( data == DATA_77 ) ;
									_CHECK_STEP( 23 ) ;
	ercd = tsnd_dtq( DTQ_ID1, DATA_11, TMO_POL ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 25 ) ;
	ercd = wup_tsk( TASK_ID3 ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = act_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd = act_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = psnd_dtq( DTQ_ID2, DATA_66 ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = dly_tsk( DLYTIM_50 ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ercd = prcv_dtq( DTQ_ID1, p_data ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT( data == DATA_11 ) ;
									_CHECK_STEP( 44 ) ;
	ercd = dly_tsk( DLYTIM_1000 ) ;
									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 48 ) ;
	ercd = rel_wai( TASK_ID1 ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ercd = chg_pri( TASK_ID2, TSKPRI_3 ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 54 ) ;
	ercd = wup_tsk( TASK_ID3 ) ;
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ercd = wup_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 62 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;
									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	ercd = prcv_dtq( DTQ_ID2, p_data ) ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT( data == DATA_66 ) ;
									_CHECK_STEP( 71 ) ;
	ercd = prcv_dtq( DTQ_ID2, p_data ) ;
									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 75 ) ;
	_CHECK_ASSERT( data == DATA_99 ) ;
									_CHECK_STEP( 76 ) ;
	ercd = prcv_dtq( DTQ_ID2, p_data ) ;
									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT( data == DATA_77 ) ;
									_CHECK_STEP( 81 ) ;
	ercd = prcv_dtq( DTQ_ID2, p_data ) ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	_CHECK_ASSERT( data == DATA_88 ) ;
									_CHECK_STEP( 84 ) ;
	ext_tsk() ;
}

