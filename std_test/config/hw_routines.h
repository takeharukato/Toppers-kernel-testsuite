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
 */

/*-------ハードウェア依存のルーチンの定義------*/

#ifdef SH7727
//----SPC04
/*---timer interrupt ---*/
#define IPRA  (volatile short *)0xfffffee2
#define  TSTR (volatile char *) 0xfffffe92

#define TCOR1   (volatile int *) 0xfffffea0
#define TCNT1  (volatile int *)0xfffffea4
#define TCR1 (volatile short *) 0xfffffea8
#define TIMER1_START_BIT 0x01
#define PRI_BIT1 0x08

#define TCOR2   (volatile int *) 0xfffffeac
#define TCNT2  (volatile int *)0xfffffeb0
#define TCR2 (volatile short *) 0xfffffeb4
#define TIMER2_START_BIT 0x02
#define PRI_BIT2 0x04

#define TIMER_PRI   0x01
#define UNIE_BIT 0x05
#define TPSC0_BIT   0x0

#define TIMER_COUNT 0x01
#define TIMER_10MSEC  1600000

#define RAISE_INTERRUPT  raise_interrupt
#define CLEAR_INTERRUPT clear_timer
#define RAISE_INTERRUPT1_10ms test_raise_interrupt_10ms

#define RAISE_CPU_EXCEPTION1	   load_error
#define RAISE_CPU_EXCEPTION2	   load_error2

inline void start_timer(int timer_count)
{    int i=0;
    
#if INHNO_1 == INHNO_TMU1
    *TCR1=(1 << UNIE_BIT | 1 << TPSC0_BIT);
    *TCNT1=timer_count;
    *TCOR1=timer_count;
    *IPRA|=(TIMER_PRI << PRI_BIT1);
    *TSTR|=(1 << TIMER1_START_BIT);    
#else
    *TCR2=(1 << UNIE_BIT | 1 << TPSC0_BIT);
    *TCNT2=timer_count;
    *TCOR2=timer_count;
    *IPRA|=(TIMER_PRI << PRI_BIT2);
    *TSTR|=(1 << TIMER2_START_BIT);    
#endif
}

inline void clear_timer()
{
#if INHNO_1 == INHNO_TMU1
    *TSTR&=~(1 << TIMER1_START_BIT);
    *TCR1=0x0;
#else
    *TSTR&=~(1 << TIMER2_START_BIT);
    *TCR2=0x0;
#endif
}

inline void load_error()
{
    int p=1;
    
    __raise_exception((int *)p);
}


static int __raise_exception(int *p)
{
    *((int *)p);
}

static int __raise_exception2(int *p)
{
    *((int *)p);
}
inline void load_error2()
{
    int p=1;
    
    __raise_exception2((int *)p);
}


void _test_raise_exception_back()
{
	unsigned short *p;

	p = (unsigned short *)__raise_exception;
	*p = 0x0009;
}

void _test_raise_exception_back2()
{
	unsigned short *p;

	p = (unsigned short *)__raise_exception2;
	*p = 0x0009;
}

inline void raise_interrupt()
{
    start_timer(0x01);
    
}

inline void test_raise_interrupt_10ms()
{
    start_timer(TIMER_10MSEC);

}
/*-----------------------------*/
#endif
