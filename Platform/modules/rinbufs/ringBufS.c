/*********************************************************************
 *    FILE: ringBufS.c
 *
 *    These files contain the attributes and methods needed to manage
 *    a ring buffer. It turns out that we do this so much, that it may
 *    be a good idea to just make a library that does this.
 *
 *      BY:   Ken Wada
 *            Aurium Technologies Inc.
 *            15-July-2013
 *
 *    THE COMPANY: Aurium Technologies Inc.
 * 
 *    THIS FIRMWARE IS FREE TO USE AND TO MODIFY. IT IS PRESENTED HERE FOR
 *    DEMONSTRATION PURPOSES AS AN EXAMPLE ON HOW TO CODE FOR ANY DEEPLY
 *    EMBEDDED SYSTEM.
 *
 *    AS A RESULT, THE COMPANY SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
 *    INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 *    FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY USERS OF
 *    THE CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR
 *    PRODUCTS.
 *********************************************************************/
#include  <string.h>
#include  "modulo.h"
#include  "ringBufS.h"

#if ( CFG_MOD_RB > 0 )
void ringBufS_init (ringBufS *_this, unsigned char *buf, unsigned int buf_size)
{
    /*****
      The following clears:
        -> buf
        -> head
        -> tail
        -> count
      and sets head = tail
    ***/
    memset (_this, 0, sizeof (*_this));
    _this->buf = buf;
    _this->buf_size= buf_size;
}

int ringBufS_empty (ringBufS *_this)
{
    return (0 == _this->count);
}

void ringBufS_flush (ringBufS *_this, const int clearBuffer)
{
  _this->count  = 0;
  _this->head   = 0;
  _this->tail   = 0;

  if (clearBuffer)
  {
    memset (_this->buf, 0, sizeof (_this->buf));
  }
}

int ringBufS_full (ringBufS *_this)
{
    return (_this->count >= _this->buf_size);
}

int ringBufS_get (ringBufS *_this)
{
    int c;
    if (_this->count>0)
    {
      c           = _this->buf[_this->tail];
      _this->tail = modulo_inc (_this->tail, _this->buf_size);
      --_this->count;
    }
    else
    {
      c = -1;
    }

    return (c);
}

void ringBufS_put (ringBufS *_this, const unsigned char c)
{
    if (_this->count < _this->buf_size)
    {
      _this->buf[_this->head] = c;
      _this->head = modulo_inc (_this->head, _this->buf_size);
      ++_this->count;
    }
}
#endif
