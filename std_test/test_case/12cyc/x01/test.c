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

#define _TEST_TIME 3
#define _LAST_STEP 46
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void dummy();

T_CCYC k_ccyc1 = { TA_HLNG|TA_STA, EXINF_CYC1, CYCHDR_1, CYCTIM_10, CYCPHS_5   } ;
T_CCYC k_ccyc2 = { TA_HLNG|TA_PHS, EXINF_CYC2, CYCHDR_2, CYCTIM_55, CYCPHS_5   } ;
T_CCYC e_ccyc1 = { TA_HLNG       , EXINF_CYC1, (FP)dummy, CYCTIM_10, CYCPHS_0   } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = cre_cyc( ERR_CYC_ID, &e_ccyc1 ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_ccyc = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = cre_cyc( E_CYC_ID1, pk_ccyc ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	k_ccyc = e_ccyc1 ;
	k_ccyc.cycatr = ERR_CYCATR ;
									_CHECK_STEP( 7 ) ;
	ercd = cre_cyc( E_CYC_ID2, &k_ccyc ) ;
									_CHECK_STEP( 8 ) ;
	_CHECK_ASSERT_E_RSATR( ercd ) ;
									_CHECK_STEP( 9 ) ;
#ifdef ERR_POINTER
	k_ccyc = e_ccyc1 ;
	k_ccyc.cychdr =  ERR_POINTER ;
									_CHECK_STEP( 10 ) ;
	ercd = cre_cyc( E_CYC_ID3, &k_ccyc ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 10 ) ;
									_CHECK_STEP( 11 ) ;
#endif
									_CHECK_STEP( 12 ) ;
	k_ccyc = e_ccyc1 ;
	k_ccyc.cyctim =  0 ;
									_CHECK_STEP( 13 ) ;
	ercd = cre_cyc( E_CYC_ID4, &k_ccyc ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = cre_cyc( E_CYC_ID5, &e_ccyc1 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = cre_cyc( E_CYC_ID5, &e_ccyc1 ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 19 ) ;

	ercd = cre_cyc( CYC_ID1, &k_ccyc1 ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = cre_cyc( CYC_ID2, &k_ccyc2 ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 23 ) ;

	cyc_work1 = cyc_work2 = 0 ;
									_CHECK_STEP( 24 ) ;
	ercd = dly_tsk( DLYTIM_100 ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT( cyc_work2 == 0 ) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT( cyc_work1 >= 9 ) ;
									_CHECK_STEP( 28 ) ;
	ercd = stp_cyc( CYC_ID1 ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	work = cyc_work1 ;
									_CHECK_STEP( 31 ) ;
	ercd = dly_tsk( DLYTIM_100 ) ;
									_CHECK_STEP( 32 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT( cyc_work1 == work ) ;
									_CHECK_STEP( 34 ) ;

	ercd = sta_cyc( CYC_ID2 ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = dly_tsk( CYCTIM_55 ) ;
work = cyc_work2 ;
									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	_CHECK_ASSERT( work == 1 ) ;
_PRINT_VER( work ) ;
									_CHECK_STEP( 39 ) ;

	ercd = sta_cyc( CYC_ID2 ) ;
									_CHECK_STEP( 40 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 41 ) ;

	ercd = dly_tsk( CYCTIM_55 ) ;
									_CHECK_STEP( 42 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT( cyc_work2 == 2  || cyc_work2 == 3 ) ;
									_CHECK_STEP( 44 ) ;
	ercd = stp_cyc( CYC_ID2 ) ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 46 ) ;
	ext_tsk() ;
}

void CYCHDR_1( VP_INT exinf )
{
	_CHECK_ASSERT( exinf == EXINF_CYC1 ) ;
	cyc_work1++ ;
	return ;
}

void CYCHDR_2( VP_INT exinf )
{
	_CHECK_ASSERT( exinf == EXINF_CYC2 ) ;
	cyc_work2++ ;
	return ;
}

void dummy( VP_INT exinf )
{
	return ;
}
