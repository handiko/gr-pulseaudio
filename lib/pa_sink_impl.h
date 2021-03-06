/* -*- c++ -*- */
/*
 * Copyright 2013 Phil Frost.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_PULSEAUDIO_PA_SINK_IMPL_H
#define INCLUDED_PULSEAUDIO_PA_SINK_IMPL_H

#include <gr-pulseaudio/pa_sink.h>
#include "pa_simple_connection.h"

#include <pulse/simple.h>

namespace gr {
  namespace pulseaudio {

    class pa_sink_impl : public pa_sink
    {
    private:
      pa_simple_connection pa_connection;

    public:
      pa_sink_impl(
          int samp_rate,
          int nchannels,
          const char *application_name,
          const char *device,
          const char *stream_name,
          const char *channel_map);
      ~pa_sink_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace pulseaudio
} // namespace gr

#endif /* INCLUDED_PULSEAUDIO_PA_SINK_IMPL_H */

