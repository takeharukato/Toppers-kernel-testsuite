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

#define _TEST_TIME 3
#define _LAST_STEP 42
#define _NEED_TEST_ROUTINES
#include "test_com.h"

void TASK1(VP_INT exinf)
{
	ER ercd ;
									_CHECK_STEP( 1 ) ;
	pk_rovr = &k_rovr ;
	ercd = ref_ovr( ERR_TASK_ID, pk_rovr ) ;
									_CHECK_STEP( 2 ) ;
	_CHECK_ASSERT_E_ID( ercd ) ;
									_CHECK_STEP( 3 ) ;
#ifdef ERR_POINTER
	pk_rmbf = ERR_POINTER ;
									_CHECK_STEP( 4 ) ;
	ercd = ref_mbf( MBF_ID2, pk_rmbf ) ;
									_CHECK_STEP( 5 ) ;
	_CHECK_ASSERT_E_PAR( ercd ) ;
#else
									_CHECK_STEP( 4 ) ;
									_CHECK_STEP( 5 ) ;
#endif
									_CHECK_STEP( 6 ) ;
	ercd = ref_ovr( E_TASK_ID1, pk_rovr ) ;
									_CHECK_STEP( 7 ) ;
	_CHECK_ASSERT_E_NOEXS( ercd ) ;
									_CHECK_STEP( 8 ) ;
	ercd = ref_ovr( TSK_SELF, pk_rovr ) ;
									_CHECK_STEP( 9 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 10 ) ;
	_CHECK_ASSERT( k_rovr.ovrstat == TOVR_STP ) ;
									_CHECK_STEP( 11 ) ;
	_CHECK_ASSERT( k_rovr.leftotm == 0 ) ;
_PRINT_VER( k_rovr.leftotm) ;
									_CHECK_STEP( 12 ) ;
	ovr_work1 = ovr_work2 = 0 ;
									_CHECK_STEP( 13 ) ;

	ercd = sta_ovr( TASK_ID1, OVRTIM_1000 ) ;
									_CHECK_STEP( 14 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 15 ) ;
	ercd = sta_ovr( TASK_ID2, OVRTIM_50 ) ;
									_CHECK_STEP( 16 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 17 ) ;
	ercd = ref_ovr( TASK_ID1, pk_rovr ) ;
									_CHECK_STEP( 18 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 19 ) ;
	_CHECK_ASSERT( k_rovr.ovrstat == TOVR_STA ) ;
									_CHECK_STEP( 20 ) ;
	_CHECK_ASSERT( k_rovr.leftotm == OVRTIM_1000) ;
_PRINT_VER( k_rovr.leftotm) ;
									_CHECK_STEP( 21 ) ;

	ercd = ref_ovr( TASK_ID2, pk_rovr ) ;
									_CHECK_STEP( 22 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 23 ) ;
	_CHECK_ASSERT( k_rovr.ovrstat == TOVR_STA ) ;
									_CHECK_STEP( 24 ) ;
	_CHECK_ASSERT( k_rovr.leftotm == OVRTIM_50 ) ;
_PRINT_VER( k_rovr.leftotm) ;
									_CHECK_STEP( 25 ) ;
	ercd = act_tsk( TASK_ID2 ) ;
									_CHECK_STEP( 26 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 27 ) ;

									_CHECK_STEP( 28 ) ;

	ercd = ref_ovr( TASK_ID2, pk_rovr ) ;
									_CHECK_STEP( 29 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 30 ) ;
	_CHECK_ASSERT( k_rovr.ovrstat == TOVR_STA ) ;
									_CHECK_STEP( 31 ) ;
	_CHECK_ASSERT( k_rovr.leftotm > 0 && k_rovr.leftotm <= OVRTIM_50 ) ;
_PRINT_VER( k_rovr.leftotm) ;
									_CHECK_STEP( 32 ) ;

	ercd = stp_ovr( TASK_ID2 ) ;
									_CHECK_STEP( 33 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 34 ) ;
	ercd = ref_ovr( TASK_ID2, pk_rovr ) ;
									_CHECK_STEP( 35 ) ;
	_CHECK_ASSERT_E_OK( ercd ) ;
									_CHECK_STEP( 36 ) ;
	_CHECK_ASSERT( k_rovr.ovrstat == TOVR_STP ) ;
									_CHECK_STEP( 37 ) ;
_PRINT_VER( k_rovr.leftotm) ;
									_CHECK_STEP( 38 ) ;
	pk_dovr = NULL ;
									_CHECK_STEP( 39 ) ;
	ercd = def_ovr( pk_dovr ) ;
									_CHECK_STEP( 40 ) ;
	ercd = ref_ovr( TASK_ID2, pk_rovr ) ;
									_CHECK_STEP( 41 ) ;
	_CHECK_ASSERT_E_OBJ( ercd ) ;
									_CHECK_STEP( 42 ) ;
	ext_tsk() ;
}

void TASK2(VP_INT exinf)
{
	ER ercd ;
	while (1) {

		}
}

void OVRHDR_1( ID tskid, VP_INT exinf )
{

	if(( tskid == TASK_ID1 )  &&
		( exinf == EXINF_1 ))
		ovr_work1++;
	if(( tskid == TASK_ID2 )  &&
		( exinf == EXINF_2 ))
		ovr_work2++;
}

