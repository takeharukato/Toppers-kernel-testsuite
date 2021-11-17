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
#define _LAST_STEP 61
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CMPF k_cmpf1 = { TA_TFIFO, BLKCNT_1, BLKSZ_10, NULL } ;
T_CMPF k_cmpf2 = { TA_TFIFO, BLKCNT_1, BLKSZ_10, NULL } ;
T_CMPF e_cmpf1 = { TA_TFIFO, BLKCNT_2048, BLKSZ_256, NULL } ;

ER_ID mpf_id1, mpf_id2;

VP blk_No17 ;
VP blk_No38 ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
	VP blk ;
									_CHECK_STEP( 41 ) ;
	ercd = get_mpf( mpf_id1, &blk ) ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	VP blk ;
									_CHECK_STEP( 38 ) ;
	ercd = get_mpf( mpf_id1, &blk ) ;
									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT( blk == blk_No38 ) ;
									_CHECK_STEP( 49 ) ;
	ercd = rel_wai( TASK_ID1 ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 53 ) ;
	ercd = rel_mpf( mpf_id1, blk ) ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 55 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
	VP blk ;
									_CHECK_STEP( 35 ) ;
	ercd = get_mpf( mpf_id1, &blk ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 45 ) ;
	blk_No38 = blk ;
									_CHECK_STEP( 46 ) ;
	ercd = rel_mpf( mpf_id1, blk ) ;
									_CHECK_STEP( 56 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 57 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
	ER_ID mpfid;
	UINT  mpfid_cnt = 0;
	VP blk, *p_blk = &blk ;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cmpf = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_mpf( pk_cmpf ) ;
	if ( ercd > 0 ) mpfid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cmpf = k_cmpf1 ;
	k_cmpf.mpfatr = ERR_MPFATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_mpf( &k_cmpf ) ;
	if ( ercd > 0 ) mpfid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
	k_cmpf = k_cmpf2 ;
	k_cmpf.blkcnt = BLKCNT_0 ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_mpf( &k_cmpf ) ;
	if ( ercd > 0 ) mpfid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 10 ) ;
	k_cmpf = k_cmpf2 ;
	k_cmpf.blksz = BLKSZ_0 ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_mpf( &k_cmpf ) ;
	if ( ercd > 0 ) mpfid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 13 ) ;
#ifdef ERR_POINTER
	k_cmpf = k_cmpf2 ;
	k_cmpf.mpf =  ERR_POINTER ;
									_CHECK_STEP( 14 ) ;
	ercd = acre_mpf( &k_cmpf ) ;
	if ( ercd > 0 ) mpfid_cnt++;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 14 ) ;
									_CHECK_STEP( 15 ) ;
#endif
									_CHECK_STEP( 16 ) ;
	ercd = acre_mpf( &e_cmpf1 ) ;
	if ( ercd > 0 ) mpfid_cnt++;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_NOMEM( ercd ) ;
									_CHECK_STEP( 18 ) ;
	mpf_id1 = acre_mpf( &k_cmpf1 ) ;
	if ( mpf_id1 > 0 ) mpfid_cnt++;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( mpf_id1 > 0 ) ;
_PRINT_VER( mpf_id1 ) ;
									_CHECK_STEP( 20 ) ;
	mpf_id2 = acre_mpf( &k_cmpf2 ) ;
	if ( mpf_id2 > 0 ) mpfid_cnt++;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( mpf_id2 > 0) ;
_PRINT_VER( mpf_id2 ) ;
									_CHECK_STEP( 22 ) ;

	ercd = pget_mpf( mpf_id1, &blk ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	blk_No17 = blk ;
									_CHECK_STEP( 25 ) ;
	ercd = rel_mpf( mpf_id2, blk ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = pget_mpf( mpf_id1, p_blk ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_TMOUT( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = rel_mpf( mpf_id1, blk ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = get_mpf( mpf_id1, p_blk ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( *p_blk == blk_No17 ) ;
									_CHECK_STEP( 34 ) ;
	ercd = act_tsk( TASK_ID3 ) ;

									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
	ercd = rel_mpf( mpf_id1, blk ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	while ( mpfid_cnt <= ACRE_CNT ) {
		ercd = acre_mpf( &k_cmpf1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) mpfid_cnt++;
		else break;
		}
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ext_tsk() ;
}

