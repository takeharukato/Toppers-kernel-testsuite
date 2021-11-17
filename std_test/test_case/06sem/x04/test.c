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
#define _LAST_STEP 52
#define _NEED_TEST_ROUTINES
#include "test_com.h"

T_CSEM k_csem1 = { TA_TFIFO, ISEMCNT_0,    MAXSEM_2    } ;
T_CSEM k_csem2 = { TA_TPRI,  ISEMCNT_0,    MAXSEM_2    } ;

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 22 ) ;
	ercd = wai_sem( SEM_ID2 ) ;

									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 30 ) ;
	ercd = slp_tsk() ;

									_CHECK_STEP( 39 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 40 ) ;
	ercd = wai_sem( SEM_ID1 ) ;

									_CHECK_STEP( 49 ) ;
	_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 50 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 19 ) ;
	ercd = wai_sem( SEM_ID2 ) ;

									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 32 ) ;
	ercd =slp_tsk() ;

									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	ercd = wai_sem( SEM_ID1 ) ;

									_CHECK_STEP( 47 ) ;
	_CHECK_ASSERT_E_DLT( ercd ) ;
									_CHECK_STEP( 48 ) ;
	ext_tsk() ;
}

void TASK3(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	ercd = ref_sem( ERR_SEM_ID, &k_rsem ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rsem = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_sem( SEM_ID2, pk_rsem ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_sem( SEM_ID1, &k_rsem ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_sem( SEM_ID2, &k_rsem ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rsem.wtskid == TSK_NONE ) ;
_PRINT_VER( k_rsem.wtskid) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rsem.semcnt == ISEMCNT_FFFE ) ;
_PRINT_VER( k_rsem.semcnt) ;
									_CHECK_STEP( 12 ) ;
	ercd = del_sem( SEM_ID2 ) ;
									_CHECK_STEP( 13 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 14 ) ;
	ercd = cre_sem( SEM_ID1, &k_csem1 ) ;
									_CHECK_STEP( 15 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 16 ) ;
	ercd = cre_sem( SEM_ID2, &k_csem2 ) ;
									_CHECK_STEP( 17 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 18 ) ;
	ercd = act_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 21 ) ;
	ercd = act_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 24 ) ;
	ercd = ref_sem( SEM_ID2, &k_rsem ) ;
									_CHECK_STEP( 25 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT( k_rsem.wtskid == TASK_ID1 ) ;
_PRINT_VER( k_rsem.wtskid) ;
									_CHECK_STEP( 27 ) ;
	_CHECK_ASSERT( k_rsem.semcnt == ISEMCNT_0 ) ;
_PRINT_VER( k_rsem.semcnt) ;
									_CHECK_STEP( 28 ) ;
	ercd = del_sem( SEM_ID2 ) ;

									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = wup_tsk( TASK_ID2 ) ;

									_CHECK_STEP( 37 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 38 ) ;
	ercd = wup_tsk( TASK_ID1 ) ;

									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ercd = ref_sem( SEM_ID1, &k_rsem ) ;
									_CHECK_STEP( 43 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 44 ) ;
	_CHECK_ASSERT( k_rsem.wtskid == TASK_ID2 ) ;
_PRINT_VER( k_rsem.wtskid) ;
									_CHECK_STEP( 45 ) ;
	_CHECK_ASSERT( k_rsem.semcnt == ISEMCNT_0 ) ;
_PRINT_VER( k_rsem.semcnt) ;
									_CHECK_STEP( 46 ) ;
	ercd = del_sem( SEM_ID1 ) ;

									_CHECK_STEP( 51 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 52 ) ;
	ext_tsk() ;
}

