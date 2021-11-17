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
#define _LAST_STEP 83
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
									_CHECK_STEP( 1 ) ;
	_CHECK_ASSERT( 1 == sizeof(B) ) ;
									_CHECK_STEP( 2 ) ;
	b1 = -1 ;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT( b1 < 0 ) ;
									_CHECK_STEP( 4 ) ;
	_CHECK_ASSERT( 1 == sizeof(UB) ) ;
									_CHECK_STEP( 5 ) ;
	ub1 = -1 ;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT( ub1 > 0 ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT( 2 == sizeof(H) ) ;
									_CHECK_STEP( 8 ) ;
	h1 = -1 ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT( h1 < 0 ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( 2 == sizeof(UH) ) ;
									_CHECK_STEP( 11 ) ;
	uh1 = -1 ;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT( uh1 > 0 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT( 4 == sizeof(W) ) ;
									_CHECK_STEP( 14 ) ;
	w1 = -1 ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT( w1 < 0 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT( 4 == sizeof(UW) ) ;
									_CHECK_STEP( 17 ) ;
	uw1 = -1 ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT( uw1 > 0 ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( 1 == sizeof(VB) ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( 2 == sizeof(VH) ) ;
									_CHECK_STEP( 21 ) ;
	_CHECK_ASSERT( 4 == sizeof(VW) ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT( sizeof(void *) == sizeof(VP) ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( sizeof(void (*)(void)) == sizeof(FP) ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( 2 <= sizeof(INT) ) ;
									_CHECK_STEP( 25 ) ;
	int1 = -1 ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT( int1 < 0 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT( 2 <= sizeof(UINT) ) ;
									_CHECK_STEP( 28 ) ;
	uint1 = -1 ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT( uint1 > 0 ) ;
									_CHECK_STEP( 30 ) ;
	bool1 = TRUE ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( bool1 == TRUE ) ;
									_CHECK_STEP( 32 ) ;
	bool1 = FALSE ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( bool1 == FALSE ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT( 2 <= sizeof(FN) ) ;
									_CHECK_STEP( 35 ) ;
	fn1 = -1 ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( fn1 < 0 ) ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT( 1 <= sizeof(ER) ) ;
									_CHECK_STEP( 38 ) ;
	er1 = -1 ;
									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT( er1 < 0 ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT( 2 <= sizeof(ID) ) ;
									_CHECK_STEP( 41 ) ;
	id1 = -1 ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT( id1 < 0 ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT( 1 <= sizeof(ATR) ) ;
									_CHECK_STEP( 44 ) ;
	atr1 = -1 ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( atr1 > 0 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT( 2 <= sizeof(STAT) ) ;
									_CHECK_STEP( 47 ) ;
	stat1 = -1 ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT( stat1 > 0 ) ;
									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT( 1 <= sizeof(MODE) ) ;
									_CHECK_STEP( 50 ) ;
	mode1 = -1 ;
									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT( mode1 > 0 ) ;
									_CHECK_STEP( 52 ) ;
	_CHECK_ASSERT( 2 <= sizeof(PRI) ) ;
									_CHECK_STEP( 53 ) ;
	pri1 = -1 ;
									_CHECK_STEP( 54 ) ;
	_CHECK_ASSERT( pri1 < 0 ) ;
									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT( sizeof(SIZE) == sizeof(void *) ) ;
									_CHECK_STEP( 56 ) ;
	size1 = -1 ;
									_CHECK_STEP( 57 ) ;
	_CHECK_ASSERT( size1 > 0 ) ;
									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT( 2 <= sizeof(TMO) ) ;
									_CHECK_STEP( 59 ) ;
	tmo1 = -1 ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT( tmo1 < 0 ) ;
									_CHECK_STEP( 61 ) ;
	_CHECK_ASSERT( 2 <= sizeof(RELTIM) ) ;
									_CHECK_STEP( 62 ) ;
	reltim1 = -1 ;
									_CHECK_STEP( 63 ) ;
	_CHECK_ASSERT( reltim1 > 0 ) ;
									_CHECK_STEP( 64 ) ;
	_CHECK_ASSERT( 2 <= sizeof(SYSTIM) ) ;
									_CHECK_STEP( 65 ) ;
	systim1 = -1 ;
									_CHECK_STEP( 66 ) ;
	_CHECK_ASSERT( systim1 > 0 ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT( sizeof(VP_INT) >= sizeof(INT) && sizeof(VP_INT) >= sizeof(VP) ) ;
									_CHECK_STEP( 68 ) ;
	vp_int1 = (VP_INT) -1 ;
									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT( (INT)vp_int1 < 0 ) ;
									_CHECK_STEP( 70 ) ;
	_CHECK_ASSERT( 1 <= sizeof(ER_BOOL) ) ;
									_CHECK_STEP( 71 ) ;
	er_bool1 = TRUE ;
									_CHECK_STEP( 72 ) ;
	_CHECK_ASSERT( er_bool1 == TRUE ) ;
									_CHECK_STEP( 73 ) ;
	er_bool1 = FALSE ;
									_CHECK_STEP( 74 ) ;
	_CHECK_ASSERT( er_bool1 == FALSE ) ;
									_CHECK_STEP( 75 ) ;
	er_bool1 = -1 ;
									_CHECK_STEP( 76 ) ;
	_CHECK_ASSERT( er_bool1 < 0 ) ;
									_CHECK_STEP( 77 ) ;
	_CHECK_ASSERT( 2 <= sizeof(ER_ID) ) ;
									_CHECK_STEP( 78 ) ;
	er_id1 = -1 ;
									_CHECK_STEP( 79 ) ;
	_CHECK_ASSERT( er_id1 < 0 ) ;
									_CHECK_STEP( 80 ) ;
	_CHECK_ASSERT( 2 <= sizeof(ER_UINT) ) ;
									_CHECK_STEP( 81 ) ;
	er_uint1 = -1 ;
									_CHECK_STEP( 82 ) ;
	_CHECK_ASSERT( er_uint1 < 0 ) ;
									_CHECK_STEP( 83 ) ;
	ext_tsk() ;
}
