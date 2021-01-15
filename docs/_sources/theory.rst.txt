******
Theory
******

This chapter provides some theoretical background to the larvotto project.

On the minimum image convention
===============================

This is a 1D derivation. We consider the simulation box :math:`(0,L)`, and two
particles, located at :math:`x` and :math:`y`. We seek the radius-vector
:math:`r` in the minimum image convention, defined as follows

.. math::
   :label: 20210113091846

   r=y-x+nL,
   \quad\text{where}\quad
   d(x, y)=\arg\min\bigl\{\lvert y-x+mL\rvert,m\in\mathbb Z\bigr\}.

In this section, we derive the closed-form expression of this distance. We first
observe that

.. math::

   \lvert y-x\rvert\leq L,
   \quad\text{since}\quad
   0\leq y\leq L
   \quad\text{and}\quad
   -L\leq -x\leq 0.


Without loss of generality, we can assume that :math:`x\leq y`, so that

.. math::
   :label: 20210114075613

   \lvert y-x\rvert=y-x\quad\text{and}\quad0\leq y-x\leq L.

Under the above assumption, :math:`n` in Eq. :eq:`20210113091846` must be 0 or
-1. Indeed, it results from Eq. :eq:`20210114075613` that

.. math::
   :label: 20210114082505

   nL\leq y-x+nL\leq\bigl(n+1\bigr)L.

It results from the above inequality

.. math::
   :nowrap:

   \begin{align}
      \text{for }n\geq 1:&& y-x+nL&\geq nL\geq L\\

      \text{for }n\geq-2:&& y-x+nL&\leq\bigl(n+1\bigr)L\leq-L
   \end{align}

and, in both cases

.. math::

   \lvert y-x+nL\rvert\geq L\geq\lvert y-x\rvert

The minimum is necessarily reached for :math:`n>1` and :math:`n >-2`; in other
words, the value of :math:`n` in Eq. :eq:`20210113091846` is 0 or -1. In what
follows, we discuss under which conditions we have :math:`n=-1`.

For :math:`n` to be equal to :math:`-1`, we must have

.. math::
   :label: 20210114082529

   \lvert y-x-L\rvert<y-x.

From Eq. :eq:`20210114082505`, we again observe that

.. math::
   :label: 20210114082533

   y-x-L\leq 0\quad\text{therefore}\quad\lvert y-x-L\rvert=L+x-y.

Combining Eqs. :eq:`20210114082529` and :eq:`20210114082533`, we find the condition

.. math::

   L+x-y<y-x,\quad\text{therefore}\quad 2\bigl(y-x\bigr)>L.

To sum up, we have shown that

.. math::

   \text{for}\quad x\leq y:\quad
   n=
   \begin{cases}
      0 & \text{if}\quad2r_0\leq L\\
      -1 & \text{if}\quad2r_0>L
   \end{cases}
   \quad\text{with}\quad
   r_0=y-x.

When :math:`x>y`, the above result applies if we swap :math:`x` and
:math:`y`. Therefore, minimum image radius-vector :math:`r` of any :math:`0\leq
x,y\leq L` is given by the following expression

.. math::

   r=
   \begin{cases}
      r_0-L & \text{if}\quad2r_0>L\\
      r_0+L & \text{if}\quad2r_0<-L\\
      r_0 & \text{otherwise}
   \end{cases}
   \quad\text{with}\quad
   r_0=\lvert y-x\rvert.
