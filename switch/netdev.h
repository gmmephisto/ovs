/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford
 * Junior University
 * 
 * We are making the OpenFlow specification and associated documentation
 * (Software) available for public use and benefit with the expectation
 * that others will use, modify and enhance the Software and contribute
 * those enhancements back to the community. However, since we would
 * like to make the Software available for broadest use, with as few
 * restrictions as possible permission is hereby granted, free of
 * charge, to any person obtaining a copy of this Software to deal in
 * the Software under the copyrights without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * The name and trademarks of copyright holder(s) may NOT be used in
 * advertising or publicity pertaining to the Software or any
 * derivatives without specific, written prior permission.
 */

/* Generic interface to network devices.
 *
 * Currently, there is a single implementation of this interface that supports
 * Linux.  The interface should be generic enough to be implementable on other
 * operating systems as well. */

#ifndef NETDEV_H
#define NETDEV_H 1

#include <stdbool.h>
#include <stdint.h>

struct buffer;

struct netdev;
int netdev_open(const char *name, struct netdev **);
void netdev_close(struct netdev *);
int netdev_recv(struct netdev *, struct buffer *);
void netdev_recv_wait(struct netdev *);
int netdev_send(struct netdev *, struct buffer *);
const uint8_t *netdev_get_etheraddr(const struct netdev *);
const char *netdev_get_name(const struct netdev *);
int netdev_get_mtu(const struct netdev *);
int netdev_get_speed(const struct netdev *);
uint32_t netdev_get_features(const struct netdev *);

#endif /* netdev.h */
