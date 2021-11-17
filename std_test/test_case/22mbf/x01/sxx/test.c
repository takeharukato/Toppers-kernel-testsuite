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

#define _NEED_TEST_ROUTINES
#include "test_com.h"

void task1(VP_INT exinf){}
void task1_1(VP_INT exinf){}
void task1_2(VP_INT exinf){}
void task2(VP_INT exinf){}
void task2_1(VP_INT exinf){}
void task2_2(VP_INT exinf){}
void task3(VP_INT exinf){}
void task4(VP_INT exinf){}
void task5(VP_INT exinf){}
void task6(VP_INT exinf){}
void task7(VP_INT exinf){}
void task8(VP_INT exinf){}
void task9(VP_INT exinf){}
void task10(VP_INT exinf){}
void task11(VP_INT exinf){}
void task12(VP_INT exinf){}
void task13(VP_INT exinf){}
void task14(VP_INT exinf){}
void task15(VP_INT exinf){}
void task16(VP_INT exinf){}
void texrtn_1(TEXPTN texptn, VP_INT exinf){}
void texrtn_2(TEXPTN texptn, VP_INT exinf){}
void inthdr_1( void ) {}
void exchdr_1(VP p_excinf){}
void exchdr_2(VP p_excinf){}
void inirtn_1(VP_INT exinf){}
void inirtn_2(VP_INT exinf){}
void cychdr_1(VP_INT exinf){}
void cychdr_2(VP_INT exinf){}
