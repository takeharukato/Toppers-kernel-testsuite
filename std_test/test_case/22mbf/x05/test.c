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
#define _LAST_STEP 99
#define _NEED_TEST_ROUTINES
#include "test_com.h"

VB snd_buf[MBFSZ_256];
VB rcv_buf[MBFSZ_256];

void TASK1(VP_INT exinf)
{
	ER ercd ;
	ER_UINT msgsz ;
									_CHECK_STEP( 59 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 67 ) ;
	msgsz = rcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 73 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 81 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;

									_CHECK_STEP( 84 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 85 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 94 ) ;
	_CHECK_ASSERT_E_DLT( msgsz ) ;
									_CHECK_STEP( 95 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	ER_UINT msgsz ;
									_CHECK_STEP( 56 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 63 ) ;
	msgsz = rcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT( msgsz == MSGSZ_10 ) ;
									_CHECK_STEP( 71 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 75 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;
									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 77 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MAXMSZ ) ;

									_CHECK_STEP( 88 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 89 ) ;
	msgsz = rcv_mbf( MBF_ID1, rcv_buf ) ;

									_CHECK_STEP( 91 ) ;
	_CHECK_ASSERT_E_RLWAI( msgsz ) ;
									_CHECK_STEP( 92 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	ER_UINT msgsz ;
	INT count;
									_CHECK_STEP( 1 ) ;
	ercd = snd_mbf( ERR_MBF_ID, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
	ercd = psnd_mbf( ERR_MBF_ID, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 5 ) ;
	ercd = tsnd_mbf( ERR_MBF_ID, snd_buf, MSGSZ_10, TMO_POL ) ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 7 ) ;
	ercd = snd_mbf( E_MBF_ID1, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 9 ) ;
	ercd = psnd_mbf( E_MBF_ID1, snd_buf, MSGSZ_10 ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 11 ) ;
	ercd = tsnd_mbf( E_MBF_ID1, snd_buf, MSGSZ_10, TMO_POL ) ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 13 ) ;
#ifdef ERR_POINTER
	ercd = snd_mbf( MBF_ID1, ERR_POINTER, MSGSZ_10 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = psnd_mbf( MBF_ID1, ERR_POINTER, MSGSZ_10 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = tsnd_mbf( MBF_ID1, ERR_POINTER, MSGSZ_10, TMO_POL ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 14 ) ;
									_CHECK_STEP( 15 ) ;
									_CHECK_STEP( 16 ) ;
									_CHECK_STEP( 17 ) ;
									_CHECK_STEP( 18 ) ;
#endif
									_CHECK_STEP( 19 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_0 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = psnd_mbf( MBF_ID1, snd_buf, MSGSZ_0 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = tsnd_mbf( MBF_ID1, snd_buf, MSGSZ_0, TMO_POL ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 25 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_256 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = psnd_mbf( MBF_ID1, snd_buf, MSGSZ_256 ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = tsnd_mbf( MBF_ID1, snd_buf, MSGSZ_256, TMO_POL ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = tsnd_mbf( MBF_ID1, snd_buf, MSGSZ_10, ERR_TMO ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 33 ) ;

	ercd = rcv_mbf( ERR_MBF_ID, rcv_buf ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = prcv_mbf( ERR_MBF_ID, rcv_buf ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = trcv_mbf( ERR_MBF_ID, rcv_buf, TMO_POL ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 39 ) ;
#ifdef ERR_POINTER
	ercd = rcv_mbf( MBF_ID1, ERR_POINTER ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 41 ) ;
	ercd = prcv_mbf( MBF_ID1, ERR_POINTER ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 43 ) ;
	ercd = trcv_mbf( MBF_ID1, ERR_POINTER ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 40 ) ;
									_CHECK_STEP( 41 ) ;
									_CHECK_STEP( 42 ) ;
									_CHECK_STEP( 43 ) ;
									_CHECK_STEP( 44 ) ;
#endif
									_CHECK_STEP( 45 ) ;
	ercd = trcv_mbf( MBF_ID1, snd_buf, ERR_TMO ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = rcv_mbf( E_MBF_ID1, snd_buf ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 49 ) ;

	for (count = 0 ;  count < MBFSZ_256/MSGSZ_10 ; count++) {
		memset( snd_buf, 'a'+count, MSGSZ_10 ) ;
		ercd = psnd_mbf( MBF_ID1, snd_buf, MSGSZ_10 ) ;
		if ( ercd == E_TMOUT ) break;
		}
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT( count < MBFSZ_256/MSGSZ_10 ) ;
_PRINT_VER( count ) ;
									_CHECK_STEP( 52 ) ;
	for (count = 0 ;  count < MBFSZ_256/MSGSZ_10 ; count++) {
		ercd = prcv_mbf( MBF_ID1, rcv_buf ) ;
		if ( ercd == E_TMOUT ) break;
_PRINT_VER( ercd ) ;
		if ( ercd != MSGSZ_10 ) break;
		if ('a'+count != *rcv_buf ) break;
		}
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT( 0 < count && count < MBFSZ_256/MSGSZ_10 ) ;
_PRINT_VER( count ) ;
									_CHECK_STEP( 55 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 58 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 65 ) ;
	ercd = snd_mbf( MBF_ID1, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 68 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 69 ) ;
	ercd = snd_mbf( MBF_ID2, snd_buf, MSGSZ_10 ) ;

									_CHECK_STEP( 78 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 79 ) ;
	ercd = wup_tsk(TASK_ID1 ) ;

									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 83 ) ;
	msgsz = prcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 86 ) ;
	_CHECK_ASSERT( msgsz == MAXMSZ ) ;
									_CHECK_STEP( 87 ) ;
	msgsz = prcv_mbf( MBF_ID2, rcv_buf ) ;

									_CHECK_STEP( 90 ) ;
	rel_wai( TASK_ID2 ) ;

									_CHECK_STEP( 93 ) ;
	ercd = del_mbf( MBF_ID1 ) ;

									_CHECK_STEP( 96 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 97 ) ;
	ercd = del_mbf( MBF_ID2 ) ;
									_CHECK_STEP( 98 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 99 ) ;
	ext_tsk() ;
}

