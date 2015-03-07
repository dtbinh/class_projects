/**
 * 
 * BY: Jake Orben and Matt Judy
 * 
 * */


import java.util.Iterator;

//*******************************************************************
//  LinkedBinarySearchTree.java       Java Foundations
//
//  Implements the binary tree using a linked representation.
//*******************************************************************

public class LinkedBinarySearchTree<T extends Comparable<T>> extends
		LinkedBinaryTree<T> implements BinarySearchTree<T> {
	// -----------------------------------------------------------------
	// Creates an empty binary search tree.
	// -----------------------------------------------------------------
	public LinkedBinarySearchTree() {
		super();
	}

	// -----------------------------------------------------------------
	// Creates a binary search tree with the specified element at its
	// root.
	// -----------------------------------------------------------------
	public LinkedBinarySearchTree(T element) {
		root = new BSTNode<T>(element);
	}

	// -----------------------------------------------------------------
	// Adds the specified element to this binary search tree.
	// -----------------------------------------------------------------
	public void add(T item) {
		if (root == null)
			root = new BSTNode<T>(item);
		else
			((BSTNode) root).add(item);
	}

	// -----------------------------------------------------------------
	// Removes and returns the element matching the specified target
	// from this binary search tree. Throws an ElementNotFoundException
	// if the target is not found.
	// -----------------------------------------------------------------
	public T remove(T target) {
		BSTNode<T> node = null;

		if (root != null)
			node = ((BSTNode) root).find(target);

		if (node == null)
			throw new ElementNotFoundException("Remove operation failed. "
					+ "No such element in tree.");

		root = ((BSTNode) root).remove(target);

		return node.getElement();
	}

	// -----------------------------------------------------------------
	// The following methods are left as programming projects.
	// -----------------------------------------------------------------

	// methods done by Nate Milkosky and Jake Orben.

	// Finds the min
	public T findMin() {
		BSTNode<T> i = null, j = ((BSTNode) root);
		if (j != null) {
			i = (BSTNode) j.getLeft();
			while (i != null) {
				j = (BSTNode) j.getLeft();
				i = (BSTNode) i.getLeft();
			}
		}
		return j.getElement();
	}

	// Finds the max
	public T findMax() {
		BSTNode<T> i = null, j = ((BSTNode) root);
		if (j != null) {
			i = (BSTNode) j.getRight();
			while (i != null) {
				j = (BSTNode) j.getRight();
				i = (BSTNode) i.getRight();
			}
		}
		return j.getElement();
	}

	// Returns the rotated right tree around node center.
	public BSTNode<T> rotateR(BSTNode<T> center) {
		if (center != null) {
			BSTNode<T> nextC = (BSTNode) center.getLeft();
			BSTNode<T> temp = (BSTNode) nextC.getRight();
			nextC.setRight(center);
			center.setLeft(temp);
			return nextC;
		}
		return center;
	}

	// Returns the rotated left tree around node center.
	public BSTNode<T> rotateL(BSTNode<T> center) {
		if (center != null) {
			BSTNode<T> nextC = (BSTNode) center.getRight();
			BSTNode<T> temp = (BSTNode) nextC.getLeft();
			nextC.setLeft(center);
			center.setRight(temp);
			return nextC;
		}
		return center;
	}

	public int order() {

		order = Math.ceil(Math.log10(size()) / Math.log10(2));
		return (int) order;

	}

	public int length(BTNode<T> input) {

		if (input == null) {
			return 0;
		} else {
			return 1 + Math.max(length(input.left),
					length(input.right));
		}

	}

	public boolean isBalanced(BTNode<T> left) {

		if (length(left) > order())
			return false;

		else
			return true;

	}

	public void ballancer(BTNode<T> left) {

		if (isBalanced(left) == false) {

			if (length(left.getLeft()) > length(left.getRight())) {

				rotateR((BSTNode<T>) left.getLeft());
				if (left.getRight() != null && left.getLeft() != null) {
					if (length(left.getLeft()) > length(left.getRight()))
						ballancer(left.left);
					else
						ballancer(left.right);

				}
			}

			if (length(left.getLeft()) < length(left.getRight())) {

				rotateL((BSTNode<T>) left.getLeft());
				if (left.getRight() != null && left.getLeft() != null) {
					if (length(left.getLeft()) > length(left.getRight()))
						ballancer(left.left);
					else
						ballancer(left.right);

				}
			}

		}

	}

}
