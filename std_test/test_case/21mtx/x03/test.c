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
#include "test_x03.h"
#include "kernel_id.h"

#define _TEST_TIME 2
#define _LAST_STEP 74
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CMTX k_cmtx1 = { TA_TFIFO,    0   } ;
T_CMTX k_cmtx2 =  { TA_TPRI,     0   } ;
T_CMTX k_cmtx3 =  { TA_INHERIT,  0   } ;
T_CMTX k_cmtx4 =  { TA_CEILING,  TSKPRI_2 } ;

ER_ID mtx_id1, mtx_id2, mtx_id3, mtx_id4;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 52 ) ;
	ercd = loc_mtx( mtx_id4 ) ;
									_CHECK_STEP( 53 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 54 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 57 ) ;
	ercd = loc_mtx( mtx_id3 ) ;
									_CHECK_STEP( 60 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 61 ) ;
	ercd = unl_mtx( mtx_id3 ) ;
									_CHECK_STEP( 62 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 63 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 64 ) ;
	ercd = loc_mtx( mtx_id2 ) ;
									_CHECK_STEP( 67 ) ;
	_CHECK_ASSERT_E_RLWAI( ercd ) ;
									_CHECK_STEP( 68 ) ;
	ext_tsk() ;
}

void TASK4(VP_INT exinf)
{
	ER ercd ;
	UINT  mtxid_cnt = 0;
									_CHECK_STEP( 1 ) ;
#ifdef ERR_POINTER
	pk_cmtx = ERR_POINTER ;
									_CHECK_STEP( 2 ) ;
	ercd = acre_mtx( pk_cmtx ) ;
	if ( ercd > 0 ) mtxid_cnt++;
									_CHECK_STEP( 3 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 2 ) ;
									_CHECK_STEP( 3 ) ;
#endif
									_CHECK_STEP( 4 ) ;
	k_cmtx = k_cmtx1 ;
	k_cmtx.mtxatr = ERR_MTXATR ;
									_CHECK_STEP( 5 ) ;
	ercd = acre_mtx( &k_cmtx ) ;
	if ( ercd > 0 ) mtxid_cnt++;
									_CHECK_STEP( 6 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 7 ) ;
	k_cmtx = k_cmtx4 ;
	k_cmtx.ceilpri = ERR_CEILPRI ;
									_CHECK_STEP( 8 ) ;
	ercd = acre_mtx( &k_cmtx ) ;
	if ( ercd > 0 ) mtxid_cnt++;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 10 ) ;
	k_cmtx = k_cmtx1 ;
	k_cmtx.ceilpri = ERR_CEILPRI ;
									_CHECK_STEP( 11 ) ;
	ercd = acre_mtx( &k_cmtx ) ;
	if ( ercd > 0 ) mtxid_cnt++;
									_CHECK_STEP( 12 ) ;
	_CHECK_ASSERT( ercd > 0) ;
									_CHECK_STEP( 13 ) ;
	mtx_id1 = acre_mtx( &k_cmtx1 ) ;
	if ( mtx_id1 > 0 ) mtxid_cnt++;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT( mtx_id1 > 0 ) ;
_PRINT_VER( mtx_id1 ) ;
									_CHECK_STEP( 15 ) ;
	mtx_id2 = acre_mtx( &k_cmtx2 ) ;
	if ( mtx_id2 > 0 ) mtxid_cnt++;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT( mtx_id2 > 0 ) ;
_PRINT_VER( mtx_id2 ) ;
									_CHECK_STEP( 17 ) ;
	mtx_id3 = acre_mtx( &k_cmtx3 ) ;
	if ( mtx_id3 > 0 ) mtxid_cnt++;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT( mtx_id3 > 0 ) ;
_PRINT_VER( mtx_id3 ) ;
									_CHECK_STEP( 19 ) ;
	mtx_id4 = acre_mtx( &k_cmtx4 ) ;
	if ( mtx_id4 > 0 ) mtxid_cnt++;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( mtx_id4 > 0 ) ;
_PRINT_VER( mtx_id4 ) ;
									_CHECK_STEP( 21 ) ;
	ercd = unl_mtx( mtx_id1 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 23 ) ;
	ercd = unl_mtx( mtx_id2 ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 25 ) ;
	ercd = unl_mtx( mtx_id3 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 27 ) ;
	ercd = unl_mtx( mtx_id4 ) ;
									_CHECK_STEP( 28 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 29 ) ;
	ercd = ploc_mtx( mtx_id1 ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 31 ) ;
	ercd = ploc_mtx( mtx_id2 ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	ercd = ploc_mtx( mtx_id3 ) ;
									_CHECK_STEP( 34 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 35 ) ;
	ercd = ploc_mtx( mtx_id4 ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 37 ) ;
	ercd = tloc_mtx( mtx_id1, TMO_FEVR ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 39 ) ;
	ercd = tloc_mtx( mtx_id2, TMO_POL ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 41 ) ;
	ercd = tloc_mtx( mtx_id3, TMO_POL ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 43 ) ;
	ercd = tloc_mtx( mtx_id4, TMO_POL ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT_E_ILUSE( ercd ) ;
									_CHECK_STEP( 45 ) ;
	ercd = unl_mtx( mtx_id1 ) ;
									_CHECK_STEP( 46 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 47 ) ;
	ercd = act_tsk( TASK_ID3 ) ;
									_CHECK_STEP( 48 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 49 ) ;
	ercd = act_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 50 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 51 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 55 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 56 ) ;
	ercd = unl_mtx( mtx_id4 ) ;

									_CHECK_STEP( 58 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 59 ) ;
	ercd = unl_mtx( mtx_id3 ) ;

									_CHECK_STEP( 65 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 66 ) ;
	ercd = rel_wai( TASK_ID3 ) ;

									_CHECK_STEP( 69 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 70 ) ;
	ercd = del_mtx( mtx_id2 ) ;
									_CHECK_STEP( 71 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
	if ( MERCD( ercd ) == E_OK ) mtxid_cnt--;
									_CHECK_STEP( 72 ) ;
	while ( mtxid_cnt <= ACRE_CNT ) {
		ercd = acre_mtx( &k_cmtx1 ) ;
_PRINT_VER( ercd ) ;
		if ( ercd > 0 ) mtxid_cnt++;
		else break;
		}
									_CHECK_STEP( 73 ) ;
	_CHECK_ASSERT_E_NOID( ercd ) ;
									_CHECK_STEP( 74 ) ;
	ext_tsk() ;
}

