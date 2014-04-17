#ifndef _RINGBUFS_H
#define _RINGBUFS_H
#include "platform.h"
/****************************************************************************/
/*    FILE: ringBufS.h                                                      */
/*                                                                          */
/*    These files contain the attributes and methods needed to manage a     */
/*    ring buffer. It turns out that we do this so much, that it may be a   */
/*    good idea to just make a library that does this.                      */
/*                                                                          */
/*      BY:   Ken Wada                                                      */
/*            Aurium Technologies Inc.                                      */
/*            15-July-2013                                                  */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/
/*    THE COMPANY: Aurium Technologies Inc.                                 */
/*                                                                          */
/*    THIS FIRMWARE IS FREE TO USE AND TO MODIFY. IT IS PRESENTED HERE FOR  */
/*    DEMONSTRATION PURPOSES AS AN EXAMPLE ON HOW TO CODE FOR ANY DEEPLY    */
/*    EMBEDDED SYSTEM.                                                      */
/*                                                                          */
/*    AS A RESULT, THE COMPANY SHALL NOT BE HELD LIABLE FOR ANY DIRECT,     */
/*    INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING  */
/*    FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY USERS OF     */
/*    THE CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR      */
/*    PRODUCTS.                                                             */
/****************************************************************************/
typedef struct  ringBufS
{
    unsigned char *buf;
    unsigned int buf_size;
    int head;
    int tail;
    int count;
} ringBufS;

void  ringBufS_init (ringBufS *_this, unsigned char *buf, unsigned int buf_size);
int   ringBufS_empty (ringBufS *_this);
int   ringBufS_full  (ringBufS *_this);
int   ringBufS_get   (ringBufS *_this);
void  ringBufS_put   (ringBufS *_this, const unsigned char c);
void  ringBufS_flush (ringBufS *_this, const int clearBuffer);

#endif
